/*************************************************************************
	> File Name: K.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月17日 星期四 12时10分51秒
 ************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, now, ans, i, a;
	while(scanf("%d", &n) != EOF) {
		now = 0;
		ans = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &a);
			if(a == -1) {
				if(now == 0) {
					ans ++;
				} else {
					now --;
				}
			} else {
				now += a;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
