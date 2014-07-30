/*************************************************************************
	> File Name: hdu3031.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月19日 星期六 20时02分14秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define M 1000010

struct node {
	int l, r, dis;
	int val;
} tree[M];
int g[110];

int Merge(int x, int y) {
	if(!x) return y;
	if(!y) return x;
	if(tree[x].val < tree[y].val) swap(x, y);  // 大堆
	tree[x].r = Merge(tree[x].r, y);
	if(tree[tree[x].l].dis < tree[tree[x].r].dis)
		swap(tree[x].l, tree[x].r);
	if(tree[x].r) tree[x].dis = tree[tree[x].r].dis + 1;
	else tree[x].dis = 0;
	return x;
}

int Pop(int x) {
	int l = tree[x].l;
	int r = tree[x].r;
	tree[x].l = tree[x].r = tree[x].dis = 0;
	return Merge(l, r);
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, n, m, i, j;
	int pile[110], p, x, root[2], sum[110], rra, tot;
	char op[5];
	int Happy, Wolffy;
	scanf("%d", &cas);
	Happy = Wolffy = 0;
	while(cas --) {
		scanf("%d%d", &n, &m);
		memset(g, 0, sizeof(g));
		for (i = 1; i <= m; ++i) {
			scanf("%d", &pile[i]);
		}
		tot = 1;
		for (i = 1; i <= m; ++i) {
			for (j = 1; j <= pile[i]; ++j) {
				scanf("%d", &p);
				tree[tot].l = tree[tot].r = tree[tot].dis = 0;
				tree[tot].val = p;
				g[i] = Merge(g[i], tot);
				tot++;
			}
		}
		memset(sum, 0, sizeof(sum));
		root[0] = root[1] = 0;
		for (i = 0; i < n; ++i) {
			scanf("%s", &op);
			if(op[0] == 'T') {
				scanf("%d", &x);
				root[i & 1] = Merge(g[x], root[i & 1]);
				sum[i & 1] += pile[x];
				g[x] = 0;
				pile[x] = 0;
			} else if(op[0] == 'C') {
				if(tree[root[0]].val > tree[root[1]].val) {
					root[0] = Merge(root[0], root[1]);
					sum[0] += sum[1];
					root[1] = 0;
					sum[1] = 0;
				} else {
					root[1] = Merge(root[0], root[1]);
					sum[1] += sum[0];
					root[0] = 0;
					sum[0] = 0;
				}
			} else if(op[0] == 'L') {
				root[i & 1] = Pop(root[i & 1]);
				sum[i & 1] --;
			} else if(op[0] == 'A') {
				scanf("%d", &x);
				tree[root[i & 1]].val += x;
			} else if(op[0] == 'E') {
				scanf("%d", &x);
				rra = Pop(root[i & 1]);
				tree[rra].val = x;
				root[i & 1] = Merge(rra, root[i & 1]);
			}
		}
		printf("%d:%d\n", sum[0], sum[1]);
		if(sum[0] > sum[1]) {
			Wolffy ++;
		} else {
			Happy ++;
		}
	}
	if(Happy > Wolffy) {
		printf("I will be back!!\n");
	} else {
		printf("Hahaha...I win!!\n");
	}
	return 0;
}
