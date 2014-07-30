/*************************************************************************
	> File Name: poj2631.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月25日 星期五 20时24分49秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define N 10010
#define INF 0x7F

struct Edge {
	int v, next;
	int val;
} edge[N];
int head[N], tot, dia, end, vis[N], dis[N];

void init() {
	tot = 0;
	memset(head, -1, sizeof(head));
}

void bfs(int u) {
	int queue[N], front, rear;
	int v, val, i;
	memset(vis, 0, sizeof(vis));
	memset(dis, INF, sizeof(dis));
	queue[rear ++] = u;
	vis[u] = 1;
	dis[u] = 0;
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
				if(dis[v] > dia) {
					dia = dis[v];
					end = v;
				}
				queue[rear ++] = v;
			}
		}
	}
}

void add(int u, int v, int val) {
	edge[tot].v = v;
	edge[tot].val = val;
	edge[tot].next = head[u];
	head[u] = tot ++;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int u, v, val;
	init();
	while(scanf("%d%d%d", &u, &v, &val) != EOF) {
		add(u, v, val);
		add(v, u, val);
	}
	bfs(1);
	bfs(end);
	printf("%d\n", dia);
	return 0;
}
