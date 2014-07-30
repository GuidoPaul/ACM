/*************************************************************************
	> File Name: poj1655.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月25日 星期五 20时50分17秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define N 20010
#define INF 9999999

struct Edge {
	int v, next;
} edge[2 * N];
int head[N], tot, vis[N], size[N], msz[N];
int n;

int max(const int a, const int b) {
	return a > b ? a : b;
}

void init() {
	tot = 0;
	memset(head, -1, sizeof(head));
}

void add(int u, int v) {
	edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot ++;
}

void dfs(int u) {
	int v, i;
	vis[u] = 1;
	size[u] = 0;
	msz[u] = 0;
	for (i = head[u]; i != -1; i = edge[i].next) {
		v = edge[i].v;
		if(vis[v] == 0) {
			dfs(v);
			size[u] += size[v] + 1;  // 子树大小, 孩子数
			msz[u] = max(msz[u], size[v] + 1);  // 子树中最大值
		}
	}
	msz[u] = max(msz[u], n - (size[u] + 1));  // 转移
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, i;
	int u, v, mmsz, idx;
	scanf("%d", &cas);
	while(cas --) {
		scanf("%d", &n);
		init();
		for (i = 0; i < n - 1; ++i) {
			scanf("%d%d", &u, &v);
			add(u, v);
			add(v, u);
		}
		memset(vis, 0, sizeof(vis));
		dfs(1);
		mmsz = INF;
		for (i = 1; i <= n; ++i) {
			if(mmsz > msz[i]) {
				mmsz = msz[i];
				idx = i;
			}
		}
		printf("%d %d\n", idx, mmsz);
	}
	return 0;
}
