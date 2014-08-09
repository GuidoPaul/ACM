/*************************************************************************
  > File Name: I.cpp
  > Author: Bslin
  > Mail: Baoshenglin1994@gmail.com
  > Created Time: 2014年08月02日 星期六 12时55分09秒
 ************************************************************************/


#include <stdio.h>
#include <string.h>
#define N 600

int map[N][N], vis[N], match[N];
int n, m;

bool dfs(int u) {
	int v;
	for (v = 1; v <= n; ++v) {
		if(map[u][v] && !vis[v]) {
			vis[v] = 1;
			if(match[v] == -1 || dfs(match[v])) {
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int x, y, i;
	int ans;
	while(scanf("%d%d", &n, &m) != EOF) {
		memset(map, 0, sizeof(map));
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &x, &y);
			map[x][y] = 1;
		}
		ans = 0;
		memset(match, -1, sizeof(match));
		for (i = 1; i <= n; ++i) {
			memset(vis, 0, sizeof(vis));
			if(dfs(i)) ans ++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
