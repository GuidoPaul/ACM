/*************************************************************************
	> File Name: J.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月17日 星期四 12时27分11秒
 ************************************************************************/

#include <stdio.h>
#define M 200010

int a[M];

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, t, c;
	int i, now, ans;
	while(scanf("%d%d%d", &n, &t, &c) != EOF) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		now = 0;
		ans = 0;
		for (i = 0; i < n; ++i) {
			if(a[i] <= t) {
				now ++;
				if(now >= c) {
					ans ++;
				}
			} else {
				now = 0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
