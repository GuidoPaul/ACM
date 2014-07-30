/*************************************************************************
	> File Name: hdu4861.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月23日 星期三 19时34分27秒
 ************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int k, p;
	while(scanf("%d%d", &k, &p) != EOF) {
		if(p == 2) {
			if(k % 2) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		} else {
			if((k / (p - 1)) % 2) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
	return 0;
}
