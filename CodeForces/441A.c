/*************************************************************************
	> File Name: 441A.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年06月08日 星期日 23时37分11秒
 ************************************************************************/

#include <stdio.h>
#define MAX 99999999

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, v, m, i, j, a;
	int min, ans, b[110];
	while(scanf("%d%d", &n, &v) != EOF) {
		ans = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &m);
			min = MAX;
			for (j = 0; j < m; j++) {
				scanf("%d", &a);
				if(min > a)
					min = a;
			}
			if(min < v) {
				b[ans++] = i + 1;
			}
		}
		printf("%d\n", ans);
		for (i = 0; i < ans; i++) {
			if(i == 0) printf("%d", b[i]);
			else printf(" %d", b[i]);
		}
		printf("\n");
	}
	return 0;
}
