/*************************************************************************
	> File Name: poj1679.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月04日 星期一 19时33分01秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
using namespace std;
#define N 110

struct Edge {
	int u, v, val;
	bool operator < (const Edge &b) const {
		return val < b.val;
	}
} edge[N * N];
int n, m;
int fa[N], rank[N], tot;
int mst[N];
bool flag;

void add(int u, int v, int val) {
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].val = val;
	tot++;
}

void init() {
	int i;
	for (i = 0; i < n; ++i) {
		fa[i] = i;
		rank[i] = 1;
	}
}

int getfa(int v) {
	if(fa[v] != v)
		fa[v] = getfa(fa[v]);
	return fa[v];
}

void Union(int a, int b) {
	fa[a] = b;
}

int kruskal(int arcnum) {
	int i, fa1, fa2, k, k2;
	int sum, sum2;
	init();
	sum = 0;
	for (i = 0, k = 0; i < arcnum; ++i) {
		fa1 = getfa(edge[i].u);
		fa2 = getfa(edge[i].v);
		if(fa1 != fa2) {
			Union(fa1, fa2);
			sum += edge[i].val;
			mst[k++] = i;  // 记录最小生成树使用的边序号
			if(k == n - 1) break;
		}
	}
	// 次小生成树
	for (k = 0; k < n - 1; ++k) {  // 遍历MST上所有边
		init();
		sum2 = 0;
		k2 = 0;
		for (i = 0; i < m; ++i) {
			if(mst[k] == i) continue;  // 不使用该边, 换一条边
			fa1 = getfa(edge[i].u);
			fa2 = getfa(edge[i].v);
			if(fa1 != fa2) {
				Union(fa1, fa2);
				sum2 += edge[i].val;
				k2 ++;
			}
		}
		if(k2 == n - 1) {
			if(sum == sum2) {
				flag = true;  // 次小与最小相同
				break;
			}
		}
	}
	return sum;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, i;
	int u, v, val;
	scanf("%d", &cas);
	while(cas --) {
		scanf("%d%d", &n, &m);
		tot = 0;
		for (i = 0; i < m; ++i) {
			scanf("%d%d%d", &u, &v, &val);
			add(u, v, val);
		}
		sort(edge, edge + tot);
		flag = false;
		int ans = kruskal(tot);
		if(flag) {
			printf("Not Unique!\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
