/*************************************************************************
  > File Name: C.cpp
  > Author: Bslin
  > Mail: Baoshenglin1994@gmail.com
  > Created Time: 2014年08月16日 星期六 15时37分48秒
 ************************************************************************/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100010

vector<int>p[MAXN];
long long phi[MAXN];
long long ans;
int cnt;

void euler() {
	int i, j;
	for (i = 0; i < MAXN; i ++) phi[i] = i, p[i].clear();
	for (i = 2; i < MAXN; i += 2) phi[i] /= 2, p[i].push_back(2);
	for (i = 3; i < MAXN; i += 2) {
		if(phi[i] == i) {
			for (j = i; j < MAXN; j += i) {
				phi[j] = phi[j] / i * (i - 1);
				p[j].push_back(i);
			}
		}
	}
	for (i = 1; i < MAXN; ++i) {
		phi[i] += phi[i-1];
	}
}

int cas, a, b, c, d, k, i, n;

void dfs(long long value, long long index, int flag) {
	long long res;
	int i;
	for (i = index; i < cnt; i++) {
		res = b / (value * p[n][i]);
		if(flag == 1) ans = ans - res;
		else ans = ans + res;
		dfs(value * p[n][i], i + 1, 1 - flag);
	}
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int kk = 1;
	euler();
	scanf("%d", &cas);
	while(cas--) {
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		if(k == 0) {
			printf("Case %d: 0\n", kk ++);
			continue;
		}
		b = b / k;
		d = d / k;
		if(b > d) swap(b, d);
		ans = phi[b];
		for (i = b + 1; i <= d; ++i) {
			cnt = p[i].size();
			n = i;
			ans += b;
			dfs(1, 0, 1);
		}
		printf("Case %d: %I64d\n", kk++, ans);
	}
	return 0;
}

