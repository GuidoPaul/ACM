/*************************************************************************
	> File Name: poj1330.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月31日 星期四 15时36分26秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define N 10010

struct Edge {
	int v, next;
} edge[N], qu[N];
int head[N], tot, degree[N], vis[N];
int qhead[N], tot2;
int fa[N], ans[2 * N];

void init() {
	tot = tot2 = 0;
	memset(head, -1, sizeof(head));
	memset(qhead, -1, sizeof(qhead));
	memset(vis, 0, sizeof(vis));
	memset(degree, 0, sizeof(degree));
}

void add(int u, int v) {
	edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

void add2(int u, int v) {
	qu[tot2].v = v;
	qu[tot2].next = qhead[u];
	qhead[u] = tot2++;
}

int getfa(int v) {
	if(v != fa[v])
		fa[v] = getfa(fa[v]);
	return fa[v];
}

void LCA(int u) {
	int v, i;
	fa[u] = u;
	vis[u] = 1;
	for (i = head[u]; i != -1; i = edge[i].next) {
		v = edge[i].v;
		if(!vis[v]) {
			LCA(v);
			fa[v] = u;
		}
	}
	for (i = qhead[u]; i != -1; i = qu[i].next) {
		v = qu[i].v;
		if(vis[v]) {
			ans[i] = ans[i ^ 1] = fa[getfa(v)];
		}
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, n, i;
	int u, v;
	scanf("%d", &cas);
	while(cas --) {
		init();
		scanf("%d", &n);
		for (i = 1; i < n; ++i) {
			scanf("%d%d", &u, &v);
			add(u, v);
			degree[v] ++;  // 入度+1, 找树根
		}
		scanf("%d%d", &u, &v);
		add2(u, v);
		add2(v, u);
		for (i = 1; i <= n; ++i) {
			if(!degree[i]) {
				LCA(i);
				break;
			}
		}
		printf("%d\n", ans[0]);
	}
	return 0;
}
