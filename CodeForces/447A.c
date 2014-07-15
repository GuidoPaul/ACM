/*************************************************************************
	> File Name: B.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月15日 星期二 12时11分29秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int c[310];

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int p, n, a, i;
	int ans;
	int flag;
	while(scanf("%d%d", &p, &n) != EOF) {
		memset(c, 0, sizeof(c));
		flag = 0;
		for (i = 1; i <= n; ++i) {
			scanf("%d", &a);
			a = a % p; 
			if(c[a] == 1 && flag == 0) {
				ans = i;
				flag = 1;
			}
			c[a] = 1;
		}
		if(flag) {
			printf("%d\n", ans);
		} else {
			printf("-1\n");
		}
	}
	return 0;
}
