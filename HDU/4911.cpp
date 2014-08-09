/*************************************************************************
	> File Name: hdu4911.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月06日 星期三 19时02分22秒
 ************************************************************************/

#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 100010

int a[N], b[N], c[N];

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

void add(int k, int n) {
	while(k <= n) {
		c[k] += 1;
		k += lowbit(k);
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, k, i;
	long long cnt, ans;
	while(scanf("%d%d", &n, &k) != EOF) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b, b + n);
		cnt = unique(b, b + n) - b;
		for (i = 0; i < n; ++i) {
			a[i] = lower_bound(b, b + cnt, a[i]) - b + 1;
		}
		ans = 0;
		memset(c, 0, sizeof(c));
		for (i = 0; i < n; ++i) {
			add(a[i], cnt);
			ans += (i - sum(a[i]) + 1);
		}
		ans = ans - k;
		if(ans < 0) ans = 0;
		printf("%I64d\n", ans);
	}
	return 0;
}
