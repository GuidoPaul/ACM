/*************************************************************************
	> File Name: 1008.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月14日 星期四 13时12分25秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	long long x, k, nowi, pre;
	int kk = 1;
	int flag;
	while(scanf("%I64d%I64d", &x, &k) != EOF) {
		if(x == 0 && k == 0) break;
		nowi = 1;
		pre = 0;
		flag = 0;
		while(nowi <= k) {
			if(x % nowi != 0) {
				x = (x / nowi + 1) * nowi;
			}
			if(pre == x / nowi) {
				flag = 1;
				break;
			}
			pre = x / nowi;
			nowi ++;
		}
		if(flag) {
			printf("Case #%d: %I64d\n", kk ++, x / nowi * k);
		} else {
			printf("Case #%d: %I64d\n", kk ++, x);
		}
	}
	return 0;
}
