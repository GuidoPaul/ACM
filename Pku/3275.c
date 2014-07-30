/*************************************************************************
	> File Name: poj3275.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月25日 星期五 18时44分42秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define N 1100
#define M 11000

struct node {
	int v;
	int next;
} edge[M];  // 边数
int head[N], tot, ans, vis[N];  // 顶点数

void init() {
	tot = 0;
	memset(head, -1, sizeof(head));
}

void add(int u, int v) {
	edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot;
	tot ++;
}

void dfs(int u) {
	int i;
	ans ++;
	vis[u] = 1;
	// i != -1 <==> ~i, -1的二进制为11111111
	for (i = head[u]; i != -1; i = edge[i].next) {
		if(vis[edge[i].v] == 0) {
			dfs(edge[i].v);
		}
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, i;
	int u, v;
	while(scanf("%d%d", &n, &m) != EOF) {
		init();
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &u, &v);
			add(u, v);
		}
		ans = 0;
		for (i = 1; i <= n; ++i) {
			memset(vis, 0, sizeof(vis));
			dfs(i);
		}
		ans -= n;
		printf("%d\n", n * (n - 1) / 2 - ans);
	}
	return 0;
}
