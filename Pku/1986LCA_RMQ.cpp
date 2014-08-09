/*************************************************************************
  > File Name: poj19862.c
  > Author: Bslin
  > Mail: Baoshenglin1994@gmail.com
  > Created Time: 2014年07月31日 星期四 21时31分17秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define N 100010

struct Edge {
	int v, val;
	int next;
} edge[2 * N];
int head[N], tot;
int depth;
int bn, b[N * 2];   // 深度序列
int id[N * 2];      // 对应深度序列中的结点编号
int pos[N];         // 结点在深度序列中的首位置
int dis[N];         // 结点到根的距离
int vis[N];
int log2[N], dp[N][20];

void init() {
	tot = 0;
	bn = depth = 0;
	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis));
}

void add(int u, int v, int val) {
	edge[tot].v = v;
	edge[tot].val = val;
	edge[tot].next = head[u];
	head[u] = tot++;
}

void dfs(int u) {
	int i, v, tmp;
	vis[u] = 1;
	tmp = ++depth;
	b[++bn] = tmp;
	id[tmp] = u;
	pos[u] = bn;
	for (i = head[u]; i != -1; i = edge[i].next) {
		v = edge[i].v;
		if(!vis[v]) {
			dis[v] = dis[u] + edge[i].val;
			dfs(v);
			b[++bn] = tmp;
		}
	}
}

void RMQ_Init(int n) { // 以深度序列做rmq
	int i, j;
	for (i = 1, j = -1; i <= n; ++i) {
		dp[i][0] = b[i];
		if(i & (i - 1)) log2[i] = j;
		else log2[i] = ++j;
	}
	for (j = 1; (1 << j) <= n; ++j) {
		for (i = 1; i + (1 << j) - 1 <= n; ++i) {
			dp[i][j] = min(dp[i][j-1], dp[i + (1 << (j-1))][j-1]);
		}
	}
}

int GetMin(int l, int r) {
	int k = log2[r - l + 1];
	return min(dp[l][k], dp[r - (1 << k) + 1][k]);
}

int LCA(int l, int r) {
	if (pos[l] > pos[r]) swap(l, r);
	int k = GetMin(pos[l], pos[r]);
	return id[k];
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, q, i;
	int u, v, val;
	char ch;
	while(scanf("%d%d", &n, &m) != EOF) {
		init();
		for (i = 0; i < m; ++i) {
			scanf("%d%d%d %c", &u, &v, &val, &ch);
			add(u, v, val);
			add(v, u, val);
		}
		dis[1] = 0;
		dfs(1);
		RMQ_Init(bn);
		scanf("%d", &q);
		while(q--) {
			scanf("%d%d", &u, &v);
			printf("%d\n", dis[u] + dis[v] - 2 * dis[LCA(u, v)]); 
		}
	}
	return 0;
}
