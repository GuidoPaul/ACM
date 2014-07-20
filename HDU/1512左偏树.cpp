/*************************************************************************
  > File Name: B.c
  > Author: Bslin
  > Mail: Baoshenglin1994@gmail.com
  > Created Time: 2014年07月16日 星期三 15时10分36秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define M 100010

int fa[M];

struct node {
	int l, r, dis;
	int val;
} tree[M];

int getfa(int x) {
	if (x != fa[x]) {
		fa[x] = getfa(fa[x]);
	}
	return fa[x];
}

int Merge(int x, int y) {
	if(!x)
		return y;
	if(!y)
		return x;
	if(tree[x].val < tree[y].val)  // 大堆
		swap(x, y);
	tree[x].r = Merge(tree[x].r, y);
	fa[tree[x].r] = x;  // 并查
	if(tree[tree[x].l].dis < tree[tree[x].r].dis)
		swap(tree[x].l, tree[x].r);
	if(tree[x].r)
		tree[x].dis = tree[tree[x].r].dis + 1;
	else
		tree[x].dis = 0;
	return x;
}

int Pop(int x) {
	int l = tree[x].l;
	int r = tree[x].r;
	fa[l] = l;
	fa[r] = r;
	tree[x].l = tree[x].r = tree[x].dis = 0;
	return Merge(l, r);
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, i;
	int a, b, ra, rb, rra, rrb, s;
	while(scanf("%d", &n) != EOF) {
		for (i = 1; i <= n; ++i) {
			scanf("%d", &a);
			fa[i] = i;
			tree[i].l = tree[i].r = tree[i].dis = 0;
			tree[i].val = a;
		}
		scanf("%d", &m);
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &a, &b);
			ra = getfa(a);
			rb = getfa(b);
			if(ra == rb) {
				printf("-1\n");
			} else {
				rra = Pop(ra); // ra, rb 的左右子树合并
				rrb = Pop(rb);
				tree[ra].val /= 2;
				tree[rb].val /= 2;
				ra = Merge(rra, ra); // 重新插入 ra 找到合适的位置
				rb = Merge(rrb, rb);
				s = Merge(ra, rb);
				printf("%d\n", tree[s].val);
			}
		}
	}
	return 0;
}
