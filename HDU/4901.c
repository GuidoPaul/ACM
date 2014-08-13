/*************************************************************************
	> File Name: 1005.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月31日 星期四 13时11分54秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define N 1010
#define MOD 1000000007

int dp1[N][1100], dp2[N][1100], a[N];

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int cas, n, i, v;
	int ans;
	scanf("%d", &cas);
	while(cas --) {
		scanf("%d", &n);
		for (i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		memset(dp1, 0, sizeof(dp1));
		dp1[0][0] = 1;
		for (i = 1; i <= n; ++i) {
			for (v = 0; v < 1024; ++v) {
				dp1[i][v] = dp1[i-1][v] + dp1[i-1][v^a[i]];
				if(dp1[i][v] >= MOD) dp1[i][v] -= MOD;
			}
		}
		memset(dp2, 0, sizeof(dp2));
		for (i = n; i >= 1; --i) {
			for (v = 0; v < 1024; ++v) {
				dp2[i][v] += dp2[i+1][v];
				dp2[i][v&a[i]] += dp2[i+1][v];
				if(dp2[i][v] >= MOD) dp2[i][v] -= MOD;
				if(dp2[i][v&a[i]] >= MOD) dp2[i][v&a[i]] -= MOD;
			}
			dp2[i][a[i]] ++;
		}
		ans = 0;
		for (i = 1; i <= n; ++i) {
			for (v = 0; v < 1024; ++v) {
				ans = (ans + (long long)dp1[i-1][v^a[i]] * dp2[i+1][v]) % MOD;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
