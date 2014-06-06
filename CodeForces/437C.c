/*************************************************************************
	> File Name: C.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年06月06日 星期五 23时43分47秒
 ************************************************************************/

#include <stdio.h>

int min(int a, int b) {
	return a > b ? b : a;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m;
	int a[1010], sum;
	int i, x, y;
	while(scanf("%d%d", &n, &m) != EOF) {
		for (i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sum = 0;
		for (i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			sum += min(a[x], a[y]);
		}
		printf("%d\n", sum);
	}
	return 0;
}
