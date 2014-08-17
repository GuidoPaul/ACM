/* 
 * File:   hdu1695.cpp
 * Author: guido
 *
 * Created on August 16, 2014, 10:48 PM
 */

#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define N 100000

int mu[N + 10], prime[N + 10];
bool vis[N + 10];

void Mobius() {
	memset(vis, 0, sizeof (vis));
	mu[0] = 0, mu[1] = 1;
	int tot = 0;
	for (int i = 2; i <= N; ++i) {
		if (!vis[i]) {
			prime[tot++] = i;
			mu[i] = -1;
		}
		for (int j = 0; j < tot; ++j) {
			if (i * prime[j] > N) break;
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				mu[i * prime[j]] = 0;
				break;
			} else {
				mu[i * prime[j]] = -mu[i];
			}
		}
	}
}

int main(int argc, char** argv) {

	freopen("in", "r", stdin);

	int cas, casno, a, b, c, d, k;
	long long t1, t2;
	Mobius();
	casno = 1;
	scanf("%d", &cas);
	while (cas--) {
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		if (k == 0) {
			printf("Case %d: 0\n", casno++);
			continue;
		}
		b = b / k;
		d = d / k;
		if (b > d) swap(b, d);
		t1 = t2 = 0;
		for (int i = 1; i <= b; i++) t1 += (long long) mu[i] * (b / i) * (d / i);
		for (int i = 1; i <= b; i++) t2 += (long long) mu[i] * (b / i) * (b / i);
		t1 -= t2 / 2;
		printf("Case %d: %I64d\n", casno++, t1);
	}
	return 0;
}

