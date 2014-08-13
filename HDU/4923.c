/*************************************************************************
	> File Name: hdu4923.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月07日 星期四 19时22分07秒
 ************************************************************************/

#include <stdio.h>
#define N 100010

int a[N];
double now[N][2];

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, n, i;
	int cnt;
	double ans;
	scanf("%d", &cas);
	while(cas --) {
		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		cnt = 0;
		for (i = 0; i < n; ++i) {
			now[cnt][0] = a[i];
			now[cnt][1] = 1.0;
			cnt ++;
			while(cnt >= 2) {
				if(now[cnt-1][0] / now[cnt-1][1] <= now[cnt-2][0] / now[cnt-2][1]) {
					now[cnt-2][0] += now[cnt-1][0];
					now[cnt-2][1] += now[cnt-1][1];
					cnt--;
				} else {
					break;
				}
			}
		}
		ans = 0;
		for (i = 0; i < cnt; ++i) {
			double tmp = now[i][0] / now[i][1];
			ans += (1 - tmp) * (1 - tmp) * now[i][0] + tmp * tmp * (now[i][1] - now[i][0]);
		}
		printf("%lf\n", ans);
	}
	return 0;
}
