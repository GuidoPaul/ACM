/*************************************************************************
	> File Name: 440A.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年06月08日 星期日 10时29分16秒
 ************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, i;
	long long sum, a, ans;
	sum = 0;
	while(scanf("%d", &n) != EOF) {
		sum = 0;
		for (i = 0; i < n - 1; i++) {
			scanf("%lld", &a);
			sum += a;
		}
		ans = (long long)(1 + n) * n / 2;
		ans = ans - sum;
		printf("%lld\n", ans);
	}
	return 0;
}
