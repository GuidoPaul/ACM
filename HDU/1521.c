/*************************************************************************
	> File Name: K.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月09日 星期六 14时39分49秒
 ************************************************************************/

#include <stdio.h>

int n, m, a[20];
int ans;

void dfs(int p) {
	int i;
	if(p == m) {
		ans ++;
		return ;
	}
	for (i = 0; i < n; ++i) {
		if(a[i]) {
			a[i] --;
			dfs(p + 1);
			a[i] ++;
		}
	}
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int i;
	while(scanf("%d%d", &n, &m) != EOF) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		ans = 0;
		dfs(0);
		printf("%d\n", ans);
	}
	return 0;
}
