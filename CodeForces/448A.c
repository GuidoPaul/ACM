/*************************************************************************
	> File Name: CodefA.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月17日 星期四 23时14分08秒
 ************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int a, b, c, sum1, sum2, n;
	scanf("%d%d%d", &a, &b, &c);
	sum1 = a + b + c;
	scanf("%d%d%d", &a, &b, &c);
	sum2 = a + b + c;
	scanf("%d", &n);
	if(sum1 % 5 == 0) {
		sum1 = sum1 / 5;
	} else {
		sum1 = sum1 / 5 + 1;
	}
	if(sum2 % 10 == 0) {
		sum2 = sum2 / 10;
	} else {
		sum2 = sum2 / 10 + 1;
	}
	/* printf("%d %d\n", sum1, sum2); */
	if(sum1 + sum2 <= n) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}
