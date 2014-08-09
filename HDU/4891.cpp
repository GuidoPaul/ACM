/*************************************************************************
	> File Name: 1005.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月29日 星期二 16时42分00秒
 ************************************************************************/

#include <cstdio>
#include <string.h>
using namespace std;
#define N 3050000

char str[N];

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, len, i, j, flagk, flag$, doge;
	long long space, ans, tmp1, tmp2;
	char nowk;
	while(scanf("%d", &n) != EOF) {
		ans = 1;
		tmp1 = 1;  // 竖杠数
		tmp2 = 1;  // 每段$$中的空格总数
		space = 1; // 每小段空格数
		flagk = flag$ = 0;  // 是否有"{"或"$"
		doge = 0;
		getchar();
		for (i = 0; i < n; ++i) {
			gets(str);
			len = strlen(str);
			if(doge) continue;
			for (j = 0; j < len; ++j) {
				if(str[j] == '{') {
					flagk = 1;
				} else if(str[j] == '}') {
					ans = ans * tmp1;
					tmp1 = 1;
					flagk = 0;
				} else if(str[j] == '$') {
					if(flag$ == 0) {
						flag$ = 1;
					} else {
						if(nowk == ' ') {
							tmp2 = tmp2 * space;
							if(tmp2 > 100000) tmp2 = 100001;   /////
						}
						ans = ans * tmp2;
						tmp2 = 1;
						space = 1;
						flag$ = 0;
					}
				} else {
					if(flagk) {
						if(str[j] == '|') {
							tmp1 ++;
						}
					}
					if(flag$) {
						if(str[j] == ' ') {
							space ++;
						} else {
							tmp2 = tmp2 * space;
							if(tmp2 > 100000) tmp2 = 100001;  /////
							space = 1;
						}
					}
				}
				if(ans > 100000) doge = 1;
				nowk = str[j];
			}
		}
		if(doge) {
			printf("doge\n");
		} else {
			printf("%I64d\n", ans);
		}
	}
	return 0;
}
