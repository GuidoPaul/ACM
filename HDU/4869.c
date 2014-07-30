/*************************************************************************
	> File Name: hdu4869.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月24日 星期四 09时51分08秒
 ************************************************************************/

#include <stdio.h>
#define N 100010
#define MOD 1000000009

long long f[N];

void init() {
	int i, j;
	f[0] = 1;
	for (i = 1; i < N; ++i) {
		f[i] = (f[i - 1] * i) % MOD;
	}
}

long long quickmod(long long a, long long b) {
	long long res;
	res = 1;
	while(b) {
		if(b & 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, i;
	int maxn, minn, nowmax, nowmin, x;
	long long ans;
	init();
	while(scanf("%d%d", &n, &m) != EOF) {
		maxn = minn = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &x);
			if(x <= minn) {
				nowmin = minn - x;
			} else if(x <= maxn) {
				if((x % 2) == (minn % 2)) {
					nowmin = 0;
				} else {
					nowmin = 1;
				}
			} else {
				nowmin = x - maxn;
			}

			if(x + maxn <= m) {
				nowmax = x + maxn;
			} else if(x + minn <= m){
				if((minn + x) % 2 == (m % 2)) {
					nowmax = m;
				} else {
					nowmax = m - 1;
				}
			} else {
				nowmax = 2 * m - (x + minn);
			}

			maxn = nowmax;
			minn = nowmin;
		}
		ans = 0;
		for (i = minn; i <= maxn; i += 2) {
			ans += f[m] * (quickmod((f[i] * f[m - i]) % MOD, MOD - 2) % MOD) % MOD;
		}
		printf("%I64d\n", ans % MOD);
	}
	return 0;
}
