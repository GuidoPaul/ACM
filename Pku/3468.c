/*************************************************************************
	> File Name: 3468.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月14日 星期一 08时35分50秒
 ************************************************************************/

#include <stdio.h>
#define M 101000

struct node {
	int L, R;
	long long sum, mark;
} tree[M << 2];
long long data[M], ans;

void PushUP(int p) {
	tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

void PushDown(int p) {
	if(tree[p].mark) {
		tree[p << 1].mark += tree[p].mark;
		tree[p << 1 | 1].mark += tree[p].mark;
		tree[p << 1].sum += (long long)(tree[p << 1].R - tree[p << 1].L + 1) * tree[p].mark;
		tree[p << 1 | 1].sum += (long long)(tree[p << 1 | 1].R - tree[p << 1 | 1].L + 1) * tree[p].mark;
		
		tree[p].mark = 0;
	}
}

void build(int L, int R, int p) {
	tree[p].L = L;
	tree[p].R = R;
	tree[p].mark = 0;
	if (L == R) {
		tree[p].sum = data[L];
		return ;
	}
	int mid = (L + R) >> 1;
	build(L, mid, p << 1);
	build(mid + 1, R, p << 1 | 1);
	PushUP(p);
}

void query(int L, int R, int p) {
	if (L <= tree[p].L && R >= tree[p].R) {
		ans += tree[p].sum;
		return ;
	}
	PushDown(p);
	int mid = (tree[p].L + tree[p].R) >> 1;
	if (mid >= R) query(L, R, p << 1);
	else if (mid + 1 <= L) query(L, R, p << 1 | 1);
	else {
		query(L, mid, p << 1);
		query(mid + 1, R, p << 1 | 1);
	}
}

void update(int L, int R, int c, int p) {
	if (L <= tree[p].L && R >= tree[p].R) {
		tree[p].mark += c;
		tree[p].sum += (long long)c * (tree[p].R - tree[p].L + 1);
		return ;
	}
	PushDown(p);
	int mid = (tree[p].L + tree[p].R) >> 1;
	if (mid >= R) update(L, R, c, p << 1);
	else if (mid + 1 <= L) update(L, R, c, p << 1 | 1);
	else {
		update(L, mid, c, p << 1);
		update(mid + 1, R, c, p << 1 | 1);
	}
	PushUP(p);
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, q, i;
	char op[2];
	int l, r, c;
	while(scanf("%d%d", &n, &q) != EOF) {
		for (i = 1; i <= n; ++i) {
			scanf("%lld", &data[i]);
		}
		build(1, n, 1);
		for (i = 0; i < q; ++i) {
			scanf("%s", &op);
			if(op[0] == 'Q') {
				scanf("%d%d", &l, &r);
				ans = 0;
				query(l, r, 1);
				printf("%lld\n", ans);
			} else if(op[0] == 'C') {
				scanf("%d%d%d", &l, &r, &c);
				update(l, r, c, 1);
			}
		}
	}
	return 0;
}
