/*************************************************************************
  > File Name: cf86D.c
  > Author: Bslin
  > Mail: Baoshenglin1994@gmail.com
  > Created Time: 2014年08月10日 星期日 20时01分02秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define N 200010
#define M 1000010

int n, t;
struct node {
	int l, r, b;
	int id;
	bool operator < (const node &o) const {
		if(b != o.b) return b < o.b;
		return r < o.r;
	}
} q[N];
long long ans[N], now;
int cnt[M], a[N], L, R;

//     n * n * a + x = (n + 1) * (n + 1) * a
// ==> x = (2 * n + 1) * a;
//     n * n * a - x = (n - 1) * (n - 1) * a
// ==> x = (2 * n - 1) * a;

void query(int l, int r) {
	while(L < l) {
		now -= (((cnt[a[L]] << 1) - 1) * a[L]);
		cnt[a[L]] --;
		L ++;
	}
	while(L > l) {
		L --;
		now += (((cnt[a[L]] << 1) + 1) * a[L]);
		cnt[a[L]] ++;
	}
	while(R < r) {
		R ++;
		now += (((cnt[a[R]] << 1) + 1) * a[R]);
		cnt[a[R]] ++;
	}
	while(R > r) {
		now -= (((cnt[a[R]] << 1) - 1) * a[R]);
		cnt[a[R]] --;
		R --;
	}
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int i, size;
	while(scanf("%d%d", &n, &t) != EOF) {
		for (i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		size = sqrt(1.0 * n);
		for (i = 0; i < t; ++i) {
			scanf("%d%d", &q[i].l, &q[i].r);
			q[i].b = q[i].l / size;
			q[i].id = i;
		}
		sort(q, q + t);
		now = L = R = 0;
		memset(cnt, 0, sizeof cnt);
		for (i = 0; i < t; ++i) {
			query(q[i].l, q[i].r);
			ans[q[i].id] = now;
		}
		for (i = 0; i < t; ++i) {
			printf("%lld\n", ans[i]);
		}
	}
	return 0;
}
