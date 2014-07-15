/*************************************************************************
	> File Name: hdu2492.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月15日 星期二 10时40分13秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define M 100010

long long a[M], c[M], lmin[M], lmax[M], rmin[M], rmax[M];

int lowbit(int k) {
	return k & (-k);
}

int sum(int k) {
	int ret = 0;
	while(k > 0) {
		ret += c[k];
		k -= lowbit(k);
	}
	return ret;
}

void add(int x) {
	while(x <= M) {
		c[x] ++;
		x += lowbit(x);
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, n, i;
	long long ans;
	scanf("%d", &cas);
	while(cas --) {
		scanf("%d", &n);
		for (i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		memset(c, 0, sizeof(c));
		// c 记录某段存在个数
		for (i = 1; i <= n; ++i) {
			add(a[i]);
			lmin[i] = sum(a[i] - 1);
			lmax[i] = i - 1 - lmin[i];
		}
		memset(c, 0, sizeof(c));
		for (i = n; i >= 1; i--) {
			add(a[i]);
			rmin[i] = sum(a[i] - 1);
			rmax[i] = n - i - rmin[i];
		}
		ans = 0;
		for (i = 1; i <= n; ++i) {
			ans += lmin[i] * rmax[i] + lmax[i] * rmin[i];
		}
		// hdu 输出
		printf("%I64d\n", ans);
	}
	return 0;
}
