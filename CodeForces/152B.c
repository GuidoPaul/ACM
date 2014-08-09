/*************************************************************************
	> File Name: E.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月09日 星期六 14时59分42秒
 ************************************************************************/

#include <stdio.h>
#define INF 1000000010

long long min(long long a, long long b) {
	return a > b ? b : a;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, k, i;
	int nowx, nowy, dx, dy;
	int tmp, tmp2;
	long long ans;
	while(scanf("%d%d", &n, &m) != EOF) {
		scanf("%d%d", &nowx, &nowy);
		scanf("%d", &k);
		ans = 0;
		for (i = 0; i < k; ++i) {
			scanf("%d%d", &dx, &dy);
			if(dx > 0) {
				tmp = (n - nowx) / dx;
			} else if(dx < 0) {
				tmp = (1 - nowx) / dx;
			} else {
				tmp = INF;
			}
			if(dy > 0) {
				tmp2 = (m - nowy) / dy;
			} else if(dy < 0) {
				tmp2 = (1 - nowy) / dy;
			} else {
				tmp2 = INF;
			}
			tmp = min(tmp, tmp2);
			ans += tmp;
			nowx = nowx + tmp * dx;
			nowy = nowy + tmp * dy;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
