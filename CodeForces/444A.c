/*************************************************************************
	> File Name: 444A.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月15日 星期二 20时41分46秒
 ************************************************************************/

#include <stdio.h>

double max(double a, double b) {
	return a > b ? a : b;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, i;
	int a[510], u, v, value;
	double ans;
	while(scanf("%d%d", &n, &m) != EOF) {
		for (i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (i = 0; i < m; ++i) {
			scanf("%d%d%d", &u, &v, &value);
			ans = max(ans, (double)(a[u] + a[v]) / value);
		}
		printf("%.15f\n", ans);
	}
	return 0;
}
