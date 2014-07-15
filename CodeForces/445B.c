/*************************************************************************
	> File Name: H.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月15日 星期二 13时12分24秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>

int fa[60], rank[60], cnt[60];

int getfa(int x) {
	while(x != fa[x]) {
		x = fa[x];
	}
	return x;
}

void Union(int x, int y) {
	if(rank[x] == rank[y]) {
		rank[x] ++;
		cnt[x] += cnt[y];
		fa[y] = x;
	} else if(rank[x] > rank[y]) {
		cnt[x] += cnt[y];
		fa[y] = x;
	} else {
		cnt[y] += cnt[x];
		fa[x] = y;
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, x, y, i;
	long long ans;
	while(scanf("%d%d", &n, &m) != EOF) {
		for (i = 1; i <= n; ++i) {
			fa[i] = i;
			rank[i] = 0;
			cnt[i] = 1;
		}
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &x, &y);
			x = getfa(x);
			y = getfa(y);
			if(x == y)
				continue;
			Union(x, y);
		}
		ans = 1;
		for (i = 1; i <= n; ++i) {
			if(getfa(i) == i) {
				ans *= pow(2, cnt[i] - 1);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
