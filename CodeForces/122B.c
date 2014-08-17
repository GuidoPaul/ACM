/*************************************************************************
	> File Name: cf122B.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月16日 星期六 18时41分48秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char str[60];
	int len, i, cnt4, cnt7;
	while(~scanf("%s", str)) {
		len = strlen(str);
		cnt4 = cnt7 = 0;
		for (i = 0; i < len; ++i) {
			if(str[i] == '4') {
				cnt4 ++;
			} else if(str[i] == '7') {
				cnt7 ++;
			}
		}
		if(cnt4 == cnt7 && cnt4 == 0) {
			printf("-1\n");
		} else {
			printf("%d\n", cnt4 >= cnt7 ? 4 : 7);
		}
	}
	return 0;
}
