/*************************************************************************
	> File Name: A.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年06月07日 星期六 22时33分31秒
 ************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, d, i;
	int a[110], mintime, ans;
	while(scanf("%d%d", &n, &d) != EOF) {
		mintime = (n - 1) * 10;
		ans = (n - 1) * 2;
		/* int sum = 0; */
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			/* sum += a[i]; */
			mintime += a[i];
		}
		/* printf("%d\n", sum); */
		if(mintime > d) {
			printf("-1\n");
		} else {
			printf("%d\n", ans + (d - mintime) / 5);
		}
	}
	return 0;
}
