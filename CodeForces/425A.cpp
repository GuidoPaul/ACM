/*************************************************************************
	> File Name: C.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月17日 星期四 12时57分15秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
using namespace std;

int a[210], b[210], c[210];

int cmp(int a, int b) {
	return a > b;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, i, j, k;
	int cnt, cnt2;
	int ans, sum;
	while(scanf("%d%d", &n, &m) != EOF) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		ans = -(1010 * 200);
		for (i = 0; i < n; ++i) {
			for (j = i; j < n; ++j) {
				cnt = 0, cnt2 = 0, sum = 0;
				for (k = i; k <= j; ++k) {
					b[cnt++] = a[k];
					sum += a[k];
				}
				for (k = 0; k < n; ++k) {
					if(k >= i && k <= j)
						continue;
					c[cnt2 ++] = a[k];
				}
				ans = max(ans, sum);
				sort(b, b + cnt);
				sort(c, c + cnt2, cmp);
				for (k = 0; k < m; ++k) {
					if(k < cnt && k < cnt2) {
						sum = sum - b[k] + c[k];
						ans = max(ans, sum);
					} else {
						break;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
