/*************************************************************************
	> File Name: cf451D.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月10日 星期日 12时17分01秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define N 100010

char str[N];

long long cal(long long x) {
	return (x + 1) * x / 2;
}

int main(int argc, char *argv[]) {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	int len, i;
	long long evena, odda, evenb, oddb;
	long long even, odd;
	while(scanf("%s", str) != EOF) {
		len = strlen(str);
		evena = odda = evenb = oddb = 0;
		for (i = 0; i < len; ++i) {
			if(str[i] == 'a') {
				if(i % 2 == 0) {
					evena ++;
				} else {
					odda ++;
				}
			} else {
				if(i % 2 == 0) {
					evenb ++;
				} else {
					oddb ++;
				}
			}
		}
		even = evena * odda + evenb * oddb;
		odd = cal(odda) + cal(evena) + cal(oddb) + cal(evenb);
		printf("%lld %lld\n", even, odd);
	}
	return 0;
}
