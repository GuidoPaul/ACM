/*************************************************************************
	> File Name: hdu1286.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月09日 星期六 11时36分31秒
 ************************************************************************/

#include <stdio.h>
#define N 32800

int phi[N];

void euler(int maxn) {
	int i, j;
	for (i = 1; i <= maxn; i ++) phi[i] = i;
	for (i = 2; i <= maxn; i += 2) phi[i] /= 2;
	for (i = 3; i <= maxn; i += 2) {
		if(phi[i] == i) {
			for (j = i; j <= maxn; j += i) {
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, i;
	int num, ans;
	euler(N);
	scanf("%d", &cas);
	while(cas--) {
		scanf("%d", &num);
		printf("%d\n", phi[num]);
	}
	return 0;
}
