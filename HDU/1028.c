/*************************************************************************
	> File Name: hdu1028.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月09日 星期六 10时32分49秒
 ************************************************************************/

#include <stdio.h>

long long f[130][130];

void init() {
	int i, j, k;
	f[0][0] = 1;
	f[1][0] = 1;
	for (i = 1; i <= 120; ++i) {
		f[i][1] = 1;
	}
	for (i = 2; i <= 120; ++i) {
		for (j = 2; j <= i; ++j) {
			if(i - j < j) {
				k = i - j;
			} else {
				k = j;
			}
			f[i][j] = (f[i][j-1] + f[i-j][k]);
		}
	}
}

int main(int argc, char *argv[]) {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	int n;
	init();
	while(scanf("%d", &n) != EOF) {
		printf("%I64d\n", f[n][n]);
	}
	return 0;
}
