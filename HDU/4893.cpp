/*************************************************************************
	> File Name: 1007.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月29日 星期二 13时07分08秒
 ************************************************************************/

#include <cstdio>
#include <cmath>
using namespace std;
#define N 100010

struct node {
	int L, R;
	long long sum, vsum;
	int flag;
} tree[N << 2];
long long ans;

long long ffib(long long val) {
	long long x = 0, y = 1;
	int i;
	for (i = 0; i < 100; ++i) {
		y = x + y;
		x = y - x;
		if(y >= val)
			break;
	}
	if(fabs(y - val) < fabs(x - val))
		return y;
	return x;
}

void PushUP(int p) {
	if(tree[p].L == tree[p].R) return;
	tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
	tree[p].vsum = tree[p << 1].vsum + tree[p << 1 | 1].vsum;
}

void PushDown(int p) {
	if(tree[p].flag && tree[p].L == tree[p].R) {
		tree[p].sum = tree[p].vsum;
		tree[p].flag = 0;
		return ;
	}
	if(tree[p].flag) {
		tree[p << 1].flag = tree[p << 1 | 1].flag = 1;
		tree[p << 1].sum = tree[p << 1].vsum;
		tree[p << 1 | 1].sum = tree[p << 1 | 1].vsum;
		tree[p].flag = 0;
	}
}

void build(int L, int R, int p) {
	tree[p].L = L;
	tree[p].R = R;
	tree[p].flag = 0;
	if(L == R) {
		tree[p].sum = 0;
		tree[p].vsum = 1;
		return ;
	}
	int mid = (L + R) >> 1;
	build(L, mid, p << 1);
	build(mid + 1, R, p << 1 | 1);
	PushUP(p);
}

void add(int pos, int val, int p) {
	if (tree[p].L == tree[p].R) {
		tree[p].sum += val;
		tree[p].vsum = ffib(tree[p].sum);
		tree[p].flag = 0;
		return ;
	}
	PushDown(p);
	int mid = (tree[p].L + tree[p].R) >> 1;
	if (mid >= pos) add(pos, val, p << 1);
	else add(pos, val, p << 1 | 1);
	PushUP(p);
}

void update(int L, int R, int p) {
	if (L <= tree[p].L && R >= tree[p].R) {
		tree[p].flag = 1;
		tree[p].sum = tree[p].vsum;
		return ;
	}
	PushDown(p);
	int mid = (tree[p].L + tree[p].R) >> 1;
	if (mid >= R) update(L, R, p << 1);
	else if (mid + 1 <= L) update(L, R, p << 1 | 1);
	else {
		update(L, mid, p << 1);
		update(mid + 1, R, p << 1 | 1);
	}
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
	PushUP(p);
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, i;
	int op, x, y;
	while(scanf("%d%d", &n, &m) != EOF) {
		build(1, n, 1);
		for (i = 0; i < m; ++i) {
			scanf("%d%d%d", &op, &x, &y);
			if(op == 1) {
				add(x, y, 1);
			} else if(op == 2) {
				ans = 0;
				query(x, y, 1);
				printf("%I64d\n", ans);  // hdu
			} else if(op == 3) {
				update(x, y, 1);
			}
		}
	}
	return 0;
}
