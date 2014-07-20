/*************************************************************************
	> File Name: B.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月17日 星期四 15时08分45秒
 ************************************************************************/

#include <stdio.h>
#define INF 10010

int map[110][110];

int min(int a, int b) {
	return a > b ? b : a;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, k, i, j, q;
	int all, now, ans;
	while(scanf("%d%d%d", &n, &m, &k) != EOF) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				scanf("%d", &map[i][j]);
			}
		}
		ans = INF;
		if(k < n) {
			for (i = 0; i < n; ++i) {
				all = 0;
				for (j = 0; j < n; ++j) {
					if(j == i)
						continue;
					now = 0;
					for (q = 0; q < m; ++q) {
						if(map[i][q] != map[j][q]) {
							now ++;
						}
					}
					all += min(now, m - now);
				}
				ans = min(ans, all);
			}
		} else {
			for (i = 0; i < (1 << n); ++i) {
				all = 0;
				for (j = 0; j < m; ++j) {
					now = 0;
					for (q = 0; q < n; ++q) {
						if(map[q][j] != ((i >> q) & 1)) {  // (  )
							now ++;
						}
					}
					all += min(now, n - now);
				}
				ans = min(ans, all);
			}
		}
		if(ans > k) {
			printf("-1\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
