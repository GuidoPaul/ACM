/*************************************************************************
	> File Name: A.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月16日 星期六 12时08分06秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int flag;
	int a[1010], n, i, x;
	while(~scanf("%d", &n)) {
		memset(a, 0, sizeof(a));
		flag = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &x);
			a[x] ++;
			if(a[x] > (n + 1) / 2) flag = 1;
		}
		if(flag) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
}
