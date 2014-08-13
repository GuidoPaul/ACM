/*************************************************************************
	> File Name: 1005.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月12日 星期二 14时49分35秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

long long dp[1510][1510];

long long max(long long a, long long b) {
	return a > b ? a : b;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int cas, n, t, i, x, y, z;
	long long ans, damage, time, r, g, b;
	int kk = 1;
	scanf("%d", &cas);
	while(cas--) {
		scanf("%d%d%d%d%d", &n, &x, &y, &z, &t);
		memset(dp, 0, sizeof(dp));
		ans = 0;
		for (i = 0; i < n; ++i) {
			for (g = 0; g <= i; ++g) {
				r = n - i;
				b = i - g;
				time = b * z + t;
				damage = dp[i][g] + time * r * x + time * g * y * r;
				if(ans < damage) {
					ans = damage;
				}
				dp[i + 1][g] = max(dp[i + 1][g], dp[i][g] + g * y * time);
				dp[i + 1][g + 1] = max(dp[i + 1][g + 1], dp[i][g] + g * y * time);
			}
		}
		for (i = 0; i <= n; ++i) {
			if(ans < dp[n][g]) ans = dp[n][g];
		}
		printf("Case #%d: %I64d\n", kk++, ans);
	}
	return 0;
}
