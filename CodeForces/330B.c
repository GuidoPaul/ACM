/*************************************************************************
	> File Name: G.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月02日 星期六 16时43分28秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, i, j, a, b;
	int flag[1010];
	while(scanf("%d%d", &n, &m) != EOF) {
		memset(flag, 0, sizeof(flag));
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &a, &b);
			flag[a] ++;
			flag[b] ++;
		}
		printf("%d\n", n - 1);
		for (i = 1; i <= n; ++i) {
			if(flag[i] == 0) {
				for (j = 1; j <= n; ++j) {
					if(i == j) continue;
					printf("%d %d\n", i, j);
				}
				break;
			}
		}
	}
	return 0;
}
