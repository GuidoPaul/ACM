/*************************************************************************
	> File Name: A.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月15日 星期二 12时18分01秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	char str[1010];
	int ch[40];
	int k, i, max1, len;
	while(scanf("%s", str) != EOF) {
		len = strlen(str);
		scanf("%d", &k);
		max1 = 0;
		for (i = 1; i <= 26; ++i) {
			scanf("%d", &ch[i]);
			max1 = max(max1, ch[i]);
		}
		int ans = 0;
		for (i = 0; i < len; ++i) {
			ans += (i + 1) * ch[str[i]-'a' + 1];
		}
		k = (len + 1 + len + k) * k / 2;
		ans += max1 * k;
		printf("%d\n", ans);
	}
	return 0;
}
