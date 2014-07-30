/*************************************************************************
	> File Name: hdu3265.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月21日 星期一 16时35分04秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define M 50010

struct node {
	int L, R, len;
	int flag;
} tree[M << 2];

struct Line {
	int y1, y2, x;
	int flag;
	bool operator < (const Line& b) const {
		return x < b.x;
	}
} edge[M * 8];
int tot;

void add(int y1, int y2, int x, int flag) {
	edge[tot].y1 = y1;
	edge[tot].y2 = y2;
	edge[tot].x = x;
	edge[tot++].flag = flag;
}

void Push_UP(int p) {
	if(tree[p].flag) tree[p].len = tree[p].R - tree[p].L;
	else {
		if(tree[p].L + 1 >= tree[p].R) tree[p].len = 0;
		else tree[p].len = tree[p << 1].len + tree[p << 1 | 1].len;
	}
}

void build(int L, int R, int p) {
	tree[p].L = L;
	tree[p].R = R;
	if(L + 1 >= R) {
		return ;
	}
	int mid = (L + R) >> 1;
	build(L, mid, p << 1);
	build(mid, R, p << 1 | 1);
}

void update(int L, int R, int flag, int p) {
	if(L <= tree[p].L && R >= tree[p].R) {
		tree[p].flag += flag;
		Push_UP(p);
		return ;
	}
	int mid = (tree[p].L + tree[p].R) >> 1;
	if(mid >= R) update(L, R, flag, p << 1);
	else if(mid <= L) update(L, R, flag, p << 1 | 1);
	else {
		update(L, mid, flag, p << 1);
		update(mid , R, flag, p << 1 | 1);
	}
	Push_UP(p);
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, i;
	int x1, y1, x2, y2, x3, y3, x4, y4;
	long long ans;
	while(scanf("%d", &n) != EOF) {
		if(n == 0) {
			break;
		}
		tot = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
			if(y1 != y4) {
				add(y1, y4, x1, 1);
				add(y1, y4, x3, -1);
			}
			if(y2 != y4) {
				add(y4, y2, x1, 1);
				add(y4, y2, x4, -1);
			}
			if(y1 != y3) {
				add(y1, y3, x3, 1);
				add(y1, y3, x2, -1);
			}
			if(y2 != y3) {
				add(y3, y2, x4, 1);
				add(y3, y2, x2, -1);
			}
		}
		sort(edge, edge + tot);
		build(0, M, 1);
		ans = 0;
		for (i = 0; i < tot; ++i) {
			if(i) {
				ans += (long long)tree[1].len * (edge[i].x - edge[i - 1].x);
			}
			update(edge[i].y1, edge[i].y2, edge[i].flag, 1);
		}
		printf("%I64d\n", ans);  // hdu
	}
	return 0;
}
