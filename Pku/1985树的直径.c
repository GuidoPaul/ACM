/*************************************************************************
	> File Name: poj1985.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月25日 星期五 18时30分54秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define N 100010
#define INF 99999999

struct Edge {
	int v, next;
	int val;
} edge[N];
int head[N], tot, vis[N], dis[N];  // dis 从源点出发到该点的距离
int n, m, diameter, end; // 直径, 端点

void init() {
	tot = 0;
	memset(head, -1, sizeof(head));
}

void add(int u, int v, int val) {
	edge[tot].v = v;
	edge[tot].val = val;
	edge[tot].next = head[u];
	head[u] = tot ++;
}

void bfs(int u) {
	int queue[N], front, rear;
	int i, v, val;
	memset(vis, 0, sizeof(vis));
	for (i = 1; i <= n; ++i) {
		dis[i] = INF;
	}
	front = rear = 0;
	queue[rear ++] = u;
	dis[u] = 0;
	diameter = 0;
	end = -1;
	while(front < rear) {
		u = queue[front ++];
		for (i = head[u]; i != -1; i = edge[i].next) {
			v = edge[i].v;
			val = edge[i].val;
			if(vis[v] == 0) {
				vis[v] = 1;
				if(dis[u] + val < dis[v]) {
					dis[v] = dis[u] + val;
				}
				if(dis[v] > diameter) {
					diameter = dis[v];
					end = v;
				}
				queue[rear ++] = v;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int i, j;
	int u, v, val;
	while(scanf("%d%d", &n, &m) != EOF) {
		init();
		for (i = 0; i < m; ++i) {
			scanf("%d%d%d%*s", &u, &v, &val);
			add(u, v, val);
			add(v, u, val);
		}
		bfs(1);
		bfs(end);
		printf("%d\n", diameter);
	}
	return 0;
}
