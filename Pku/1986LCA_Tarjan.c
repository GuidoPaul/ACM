/*************************************************************************
	> File Name: poj1986.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月31日 星期四 19时37分41秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define N 100010

struct Edge {
	int v, val;
	int next;
} edge[2 * N], qu[2 * N];
int head[N], qhead[N], tot, tot2;
int dis[N], vis[N], fa[N], ans[N];

void init() {
	tot = tot2 = 0;
	memset(head, -1, sizeof(head));
	memset(qhead, -1, sizeof(qhead));
	memset(dis, 0, sizeof(dis));
	memset(vis, 0, sizeof(vis));
}

void add(int u, int v, int val) {
	edge[tot].v = v;
	edge[tot].val = val;
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
	int i, v;
	fa[u] = u;   // 初始化祖先为自己本身
	vis[u] = 1;  // 标记已经访问
	for (i = head[u]; i != -1; i = edge[i].next) {
		v = edge[i].v;
		if(!vis[v]) {
			dis[v] = dis[u] + edge[i].val;  // 距离根节点距离
			LCA(v);
			fa[v] = u; // 将当前点设为该集合的祖先节点
		}
	}
	for (i = qhead[u]; i != -1; i = qu[i].next) {
		v = qu[i].v;
		if(vis[v]) {  // 因为树遍历的顺序不确定
			ans[i] = ans[i ^ 1] = dis[u] + dis[v] - 2 * dis[getfa(v)];
		}
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, i;
	int u, v, val;
	char ch;
	while(scanf("%d%d", &n, &m) != EOF) {
		init();
		for (i = 0; i < m; ++i) {
			scanf("%d%d%d %c", &u, &v, &val, &ch);
			add(u, v, val);
			add(v, u, val);
		}
		scanf("%d", &m);
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &u, &v);
			add2(u, v);  // 询问双向构造
			add2(v, u);
		}
		// 有向图通过入度找树根, 无向图LCA(1)
		LCA(1);
		for (i = 0; i < tot2; i += 2) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
