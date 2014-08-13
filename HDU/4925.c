/*************************************************************************
	> File Name: 1005.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月07日 星期四 12时18分39秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, n, m, i, j;
	long long a[110][110], ans;
	int flag;
	scanf("%d", &cas);
	while(cas --) {
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				a[i][j] = 1;
			}
		}
		flag = 0;
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				if(flag) {
					a[i-1][j] *= 2;
					a[i+1][j] *= 2;
					a[i][j-1] *= 2;
					a[i][j+1] *= 2;
				}
				flag = 1 - flag;
			}
			if(m % 2 == 0) flag = 1 - flag;
		}
		flag = 1;
		ans = 0;
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				if(flag) {
					ans += a[i][j];
				}
				flag = 1 - flag;
			}
			if(m % 2 == 0) flag = 1 - flag;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
