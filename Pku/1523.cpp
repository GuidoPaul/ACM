/*************************************************************************
	> File Name: poj1523.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月30日 星期三 19时46分12秒
 ************************************************************************/

#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 1010

struct Edge {
	int u, v;
	int next;
} edge[5000];
int head[N], tot;
int dfn[N], low[N], idx, cnt;
int cutpoint[N];
int mmin, mmax;

void init() {
	tot = 0;
	memset(head, -1, sizeof(head));
}

void add(int u, int v) {
	edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot ++;
}

void tarjan(int u) {
	int i, v;
	dfn[u] = low[u] = ++idx;
	for (i = head[u]; i != -1; i = edge[i].next) {
		v = edge[i].v;
		if(dfn[v] == -1) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
			if(low[v] >= dfn[u]) cutpoint[u] ++;
		} else if(dfn[v] < low[u]) {
			low[u] = dfn[v];
		}
	}
}

void solve() {
	int i;
	memset(dfn, -1, sizeof(dfn));
	memset(cutpoint, 0, sizeof(cutpoint));
	cnt = idx = 0;
	tarjan(mmin);
	// 根结点为割点, tarjan后处理: cutpoint[root] --;
	cutpoint[mmin] --;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int u, v, i;
	int cas = 1;
	bool flag, first = 1;
	while(scanf("%d", &u) && u) {
		init();
		scanf("%d", &v);
		mmin = u > v ? v : u;
		mmax = u > v ? u : v;
		add(u, v);
		add(v, u);
		while(scanf("%d", &u) && u) {
			scanf("%d", &v);
			mmin = min(min(mmin, u), v);
			mmax = max(max(mmax, u), v);
			add(u, v);
			add(v, u);
		}
		solve();
		if(!first) printf("\n");
		first = 0;
		printf("Network #%d\n", cas++);
		flag = 0;
		for (i = mmin; i <= mmax; ++i) {
			if(cutpoint[i]) {
				printf("  SPF node %d leaves %d subnets\n", i, cutpoint[i] + 1);
				flag = 1;
			}
		}
		if(!flag) {
			printf("  No SPF nodes\n");
		}
	}
	return 0;
}
