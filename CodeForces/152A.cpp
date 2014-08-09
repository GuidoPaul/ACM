/*************************************************************************
	> File Name: K.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月02日 星期六 12时26分24秒
 ************************************************************************/

#include <cstdio>
#include <string.h>
using namespace std;

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, i, j, k;
	char str[110][110];
	int st[110][110], ans, good[110], flag;
	while(scanf("%d%d", &n, &m) != EOF) {
		for (i = 0; i < n; ++i) {
			scanf("%s", &str[i]);
			for (j = 0; j < m; ++j) {
				st[i][j] = str[i][j] - '0';
				/* printf("%d", st[i][j]); */
			}
			/* printf("\n"); */
		}
		memset(good, 0, sizeof(good));
		ans = 0;
		int now, nowi;
		/*
		for (k = 0; k < m; ++k) {
			for (i = 0; i < n; ++i) {
				if(i == 0) {
					now = st[i][k];
					nowi = i;
				}
				if(now == st[i][k]) {
					if(good[nowi]) {
						nowi = i;
					}
				} else if(now < st[i][k]) {
					now = st[i][k];
					nowi = i;
				}
			}
			if(good[nowi] == 0) {
				printf("nowi %d %d\n", nowi, k);
				good[nowi] = 1;
				ans ++;
			}
		}
		*/
		for (i = 0; i < n; ++i) {
			for (k = 0; k < m; ++k) {
				for (j = 0; j < n; ++j) {
					if(i == j) continue;
					if(st[i][k] < st[j][k]) break;
				}
				if(j == n) {
					/* printf("%d %d\n", i, k); */
					ans ++;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
