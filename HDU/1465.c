/*************************************************************************
	> File Name: hdu1465.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月09日 星期六 11时27分13秒
 ************************************************************************/

#include <stdio.h>

long long f[30];

void init() {
	int i;
	f[2] = 1;
	f[3] = 2;
	for (i = 4; i <= 20; ++i) {
		f[i] = (f[i - 2] + f[i - 1]) * (i - 1);
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, i;
	init();
	while(scanf("%d", &n) != EOF) {
		printf("%I64d\n", f[n]);
	}
	return 0;
}
