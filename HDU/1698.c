/*************************************************************************
	> File Name: 1698.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月14日 星期一 10时29分38秒
 ************************************************************************/

#include <stdio.h>
#define M 100010

struct node {
	int L, R;
	int sum, mark;
} tree[M << 2];

void PushUP(int p) {
	tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

void PushDown(int p) {
	if(tree[p].mark) {
		tree[p << 1].mark = tree[p].mark;
		tree[p << 1 | 1].mark = tree[p].mark;
		tree[p << 1].sum = tree[p << 1].mark * (tree[p << 1].R - tree[p << 1].L + 1);
		tree[p << 1 | 1].sum = tree[p << 1 | 1].mark * (tree[p << 1 | 1].R - tree[p << 1 | 1].L + 1);

		tree[p].mark = 0;
	}
}

void build(int L, int R, int p) {
	tree[p].L = L;
	tree[p].R = R;
	tree[p].mark = 0;
	if(L == R) {
		tree[p].sum = 1;
		return ;
	}
	int mid = (L + R) >> 1;
	build(L, mid, p << 1);
	build(mid + 1, R, p << 1 | 1);
	PushUP(p);
}

void update(int L, int R, int c, int p) {
	if(L <= tree[p].L && R >= tree[p].R) {
		tree[p].mark = c;
		tree[p].sum = (tree[p].R - tree[p].L + 1) * c;
		return ;
	}
	PushDown(p);
	int mid = (tree[p].R + tree[p].L) >> 1;
	if(mid >= R) {
		update(L, R, c, p << 1);
	} else if(mid + 1 <= L) {
		update(L, R, c, p << 1 | 1);
	} else {
		update(L, mid, c, p << 1);
		update(mid + 1, R, c, p << 1 | 1);
	}
	PushUP(p);
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, n, q;
	int i, l , r, c, k;
	scanf("%d\n", &cas);
	for (k = 1; k <= cas; ++k) {
		scanf("%d%d\n", &n, &q);
		build(1, n, 1);
		for (i = 0; i < q; ++i) {
			scanf("%d%d%d\n", &l, &r, &c);
			update(l, r, c, 1);
		}
		printf("Case %d: The total value of the hook is %d.\n", k, tree[1].sum);
	}
	return 0;
}
