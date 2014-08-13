/*************************************************************************
	> File Name: hdu4902.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月06日 星期三 20时36分02秒
 ************************************************************************/

#include <stdio.h>
#define N 100010

struct node {
	int L, R;
	int val, flag;
	int maxn;
} tree[N << 2];
int a[N];

int max(int a, int b) {
	return a > b ? a : b;
}

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

void PushUP(int p) {
	if(tree[p].L == tree[p].R) return ;
	tree[p].maxn = max(tree[p << 1].maxn, tree[p << 1 | 1].maxn);
}

void PushDown(int p) {
	if(tree[p].L == tree[p].R) return ;
	if(tree[p].flag) {
		tree[p << 1].val = tree[p << 1 | 1].val = tree[p].val;
		tree[p << 1].maxn = tree[p << 1 | 1].maxn = tree[p].maxn;
		tree[p << 1].flag = tree[p << 1 | 1].flag = 1;
		tree[p].flag = 0;
	}
}

void change(int val, int p) {
	if(tree[p].maxn <= val) return ;
	if(tree[p].flag) {
		tree[p].val = tree[p].maxn = gcd(tree[p].maxn, val);
		return ;
	}
	if(tree[p].L == tree[p].R) return ;
	PushDown(p);
	change(val, p << 1);
	change(val, p << 1 | 1);
	PushUP(p);
}

void build(int L, int R, int p) {
	tree[p].L = L;
	tree[p].R = R;
	tree[p].flag = 0;
	tree[p].val = -1;
	tree[p].maxn = -1;
	if(L == R) {
		tree[p].val = a[L];
		tree[p].maxn = a[L];
		return ;
	}
	int mid = (L + R) >> 1;
	build(L, mid, p << 1);
	build(mid + 1, R, p << 1 | 1);
	PushUP(p);
}

void update(int L, int R, int val, int p) {
	if(L <= tree[p].L && R >= tree[p].R) {
		tree[p].val = val;
		tree[p].maxn = val;
		tree[p].flag = 1;
		return ;
	}
	PushDown(p);
	int mid = (tree[p].L + tree[p].R) >> 1;
	if(mid >= R) update(L, R, val, p << 1);
	else if(mid + 1 <= L) update(L, R, val, p << 1 | 1);
	else {
		update(L, mid, val, p << 1);
		update(mid + 1, R, val, p << 1 | 1);
	}
	PushUP(p);
}

void update2(int L, int R, int val, int p) {
	if(L <= tree[p].L && R >= tree[p].R) {
		change(val, p);
		return ;
	}
	PushDown(p);
	int mid = (tree[p].L + tree[p].R) >> 1;
	if(mid >= R) update2(L, R, val, p << 1);
	else if(mid + 1 <= L) update2(L, R, val, p << 1 | 1);
	else {
		update2(L, mid, val, p << 1);
		update2(mid + 1, R, val, p << 1 | 1);
	}
}

void print(int p) {
	if(tree[p].L == tree[p].R) {
		printf("%d ", tree[p].val);
		return ;
	}
	PushDown(p);
	print(p << 1);
	print(p << 1 | 1);
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, n, m, i;
	int op, ll, rr, val;
	scanf("%d", &cas);
	while(cas --) {
		scanf("%d", &n);
		for (i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		build(1, n, 1);
		scanf("%d", &m);
		for (i = 0; i < m; ++i) {
			scanf("%d%d%d%d", &op, &ll, &rr, &val);
			if(op == 1) {
				update(ll, rr, val, 1);
			} else if(op == 2) {
				update2(ll, rr, val, 1);
			}
		}
		print(1);
		printf("\n");
	}
	return 0;
}
