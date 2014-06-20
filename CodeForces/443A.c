/*************************************************************************
	> File Name: 443A.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年06月19日 星期四 23时37分12秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	char str[1010];
	int a[30], ans, len, i;
	gets(str);
	memset(a, 0, sizeof(a));
	len = strlen(str);
	for(i = 0; i < len; i ++) {
		if(str[i] >= 'a' && str[i] <= 'z') {
			a[str[i] - 'a'] = 1;
		}
	}
	ans = 0;
	for (i = 0; i < 30; i++) {
		if(a[i] == 1) {
			ans ++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
