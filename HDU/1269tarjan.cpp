/*************************************************************************
	> File Name: hdu1269.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月30日 星期三 19时11分03秒
 ************************************************************************/

#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;
#define N 10010

int n, m;
int dfn[N], low[N], idx, cnt;
int instack[N], stack[N], top;
int belong[N];
vector<int> g[N];

void tarjan(int u) {
	int i, v;
	dfn[u] = low[u] = ++idx;
	stack[++top] = u;
	instack[u] = 1;
	for (i = 0; i < g[u].size(); ++i) {
		v = g[u][i];
		if(dfn[v] == -1) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(instack[v] && dfn[v] < low[u]) {
			low[u] = dfn[v];
		}
	}
	if(dfn[u] == low[u]) {
		cnt ++;
		do {
			v = stack[top--];
			instack[v] = 0;
			belong[v] = cnt;
		} while(u != v);
	}
}

void solve() {
	int i;
	memset(dfn, -1, sizeof(dfn));
	memset(instack, 0, sizeof(instack));
	cnt = idx = top = 0;
	for (i = 1; i <= n; ++i) {
		if(dfn[i] == -1) {
			tarjan(i);
		}
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int i, u, v;
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0) break;
		for (i = 1; i <= n; ++i) {
			g[i].clear();
		}
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
		}
		solve();
		/*
		if(cnt > 1) printf("No\n");
		else printf("Yes\n");
		*/
		int flag = 0;
		for (i = 2; i <= n; ++i) {
			if(belong[i] != belong[i - 1]) {
				flag = 1;
				break;
			}
		}
		if(flag) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
