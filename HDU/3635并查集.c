/*************************************************************************
  > File Name: B.c
  > Author: Bslin
  > Mail: Baoshenglin1994@gmail.com
  > Created Time: 2014年07月19日 星期六 13时28分55秒
 ************************************************************************/

#include <stdio.h>
#define M 10010

int fa[M], num[M], trans[M];

/*
   int getfa(int x) {
   int root = x;
   while(root != fa[root]) {
   root = fa[root];
   }
   int pa = fa[x];
   while(pa != root) {
   fa[x] = root;

   trans[x] += trans[pa];  // 不仅是当前父亲的交换数, 应为一条链上的所有父亲的交换数相加

   x = pa;
   pa = fa[x];
   }
   return root;
   }
   */

int getfa(int x)  {
	int temp;
	if(x == fa[x])
		return x;
	else {
		temp = fa[x];
		fa[x] = getfa(fa[x]);
		trans[x] += trans[temp];
	}
	return fa[x];
}

void Union(int a, int b) {
	fa[a] = b;
	num[b] += num[a];
	num[a] = 0;
	trans[a] ++;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, n, m, i, k;
	char op[2];
	int a, b, ra, rb;
	scanf("%d", &cas);
	for (k = 1; k <= cas; ++k) {
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; ++i) {
			fa[i] = i;
			num[i] = 1;
			trans[i] = 0;
		}
		printf("Case %d:\n", k);
		for (i = 0; i < m; ++i) {
			scanf("%s", &op);
			if(op[0] == 'T') {
				scanf("%d%d", &a, &b);
				ra = getfa(a);
				rb = getfa(b);
				if(ra != rb) {
					Union(ra, rb);
				}
			} else if(op[0] == 'Q') {
				scanf("%d", &a);
				ra = getfa(a);
				printf("%d %d %d\n", ra, num[ra], trans[a]);
			}
		}
	}
	return 0;
}
