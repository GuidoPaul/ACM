/*************************************************************************
  > File Name: cf402E.c
  > Author: Bslin
  > Mail: Baoshenglin1994@gmail.com
  > Created Time: 2014年07月30日 星期三 18时19分53秒
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define N 2010

int n, data[N][N];
int dfn[N], low[N], visitNum;
int instack[N], stack[N], top, cnt;

int min(int a, int b) {
	return a > b ? b : a;
}

int nextInt() {
	char ch;
	int res = 0;
	while(ch = getchar(), !isdigit(ch));
	do {
		res = (res << 3) + (res << 1) + (ch - '0');
	} while(ch = getchar(), isdigit(ch));
	return res;
}

void tarjan(int u) {
	int v;
	dfn[u] = low[u] = ++visitNum;
	stack[++top] = u;
	instack[u] = 1;
	for (v = 1; v <= n; ++v) {
		if(!data[u][v]) continue;
		if(dfn[v] == -1) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(instack[v] && dfn[v] < low[u]) {
			low[u] = dfn[v];
		}
	}
	if(low[u] == dfn[u]) {
		cnt ++;
		do {
			v = stack[top--];
			instack[v] = 0;
		} while(v != u);
	}
}

void solve() {
	int i;
	memset(dfn, -1, sizeof(dfn));
	memset(instack, 0, sizeof(instack));
	cnt = top = visitNum = 0;
	for (i = 1; i <= n; ++i) {
		if(dfn[i] == -1) {
			tarjan(i);
		}
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int i, j;
	while(scanf("%d", &n) != EOF) {
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				data[i][j] = nextInt();
				if(data[i][j]) {
					data[i][j] = 1;
				}
			}
		}
		solve();
		if(cnt > 1) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
}
