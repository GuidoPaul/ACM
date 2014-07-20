/*************************************************************************
	> File Name: A.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月17日 星期四 21时27分50秒
 ************************************************************************/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define M 100010

int a[M], b[M], dp[2][M];

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, s, e, i, j;
	int x, ans;
	while(scanf("%d%d%d%d", &n, &m, &s, &e) != EOF) {
		vector<int> v[M];
		vector<int>::iterator it;
		for (i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (i = 1; i <= m; ++i) {
			scanf("%d", &x);
			v[x].push_back(i);
		}
		for (j = 0; j <= n; ++j) {
			dp[0][j] = 0;
		}
		ans = 0;
		for (i = 1; i < 305; ++i) {
			for (j = 0; j <= n; ++j) {
				dp[i % 2][j] = m + 1;
			}
			for (j = 1; j <= n; ++j) {
				int k = dp[(i - 1) % 2][j - 1];
				dp[i % 2][j] = dp[i % 2][j - 1];
				it = upper_bound(v[a[j]].begin(), v[a[j]].end(), k);
				if(it != v[a[j]].end()) {
					dp[i % 2][j] = min(dp[i % 2][j], *it);
				} else {
					continue;
				}
				if(dp[i % 2][j] <= m) {
					if(dp[i % 2][j] + j + i * e <= s) {
						ans = max(ans, i);
					}
				}	
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
