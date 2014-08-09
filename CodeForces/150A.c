/*************************************************************************
	> File Name: F.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月09日 星期六 15时31分39秒
 ************************************************************************/

#include <stdio.h>

int now[10000];

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	long long n, i, tmp;
	int cnt;
	while(scanf("%lld", &n) != EOF) {
		cnt = 0;
		tmp = n;
		for (i = 2; i * i <= tmp; ++i) {
			if(tmp % i == 0) {
				while(tmp % i == 0) {
					tmp /= i;
					now[cnt++] = i;
				}
				if(cnt >= 2) break;
			}
		}
		if(tmp != 1 && tmp != n) now[cnt ++] = n;
		if(cnt == 0 || cnt == 1) {
			printf("1\n0\n");
		} else if(cnt == 2) {
			printf("2\n");
		} else {
			printf("1\n");
			printf("%d\n", now[0] * now[1]);
		}
	}
	return 0;
}
