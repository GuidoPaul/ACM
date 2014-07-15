/*************************************************************************
	> File Name: hdu1232.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月14日 星期一 14时43分09秒
 ************************************************************************/

#include <stdio.h>

int fa[1010];
int ans;

int getfa(int x) {
	while(x != fa[x]) {
		x = fa[x];
	}
	return x;
}

void Union(int x, int y) {
	x = getfa(x);
	y = getfa(y);
	if(x != y) {
		fa[x] = y;
		ans --;
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m;
	int i, x, y;
	while(scanf("%d", &n), n) {
		scanf("%d", &m);
		for (i = 1; i <= n; ++i) {
			fa[i] = i;
		}
		ans = n - 1;
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &x, &y);
			Union(x, y);
		}
		printf("%d\n", ans);
	}
	return 0;
}

