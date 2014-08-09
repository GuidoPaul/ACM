/*************************************************************************
	> File Name: G.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月09日 星期六 12时43分06秒
 ************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, i;
	char str[60];
	int flag, start, sum1, sum2, len;
	while(scanf("%d", &n) != EOF) {
		scanf("%s", str);
		sum1 = sum2 = 0;
		flag = 0;
		for (i = 0; i < n; ++i) {
			if(str[i] != '4' && str[i] != '7') {
				flag = 1;
				break;
			} else if(i < n / 2) {
				sum1 += str[i] - '0';
			} else {
				sum2 += str[i] - '0';
			}
		}
		if(flag) {
			printf("NO\n");
			continue;
		}
		if(sum1 != sum2) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
}
