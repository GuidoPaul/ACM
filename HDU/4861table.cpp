/*************************************************************************
	> File Name: hdu4861table.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月23日 星期三 19时06分44秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int prime[10] = { 2, 3, 5, 7, 11, 13 };

int main(int argc, char *argv[]) {
	int k, p, i, j;
	int ans;
	for (k = 2; k <= 5; ++k) {
		for (p = 0; p <= 5; ++p) {
			printf("k = %d, p = %d\n", k, prime[p]);
			for (i = 1; i <= k; ++i) {
				ans = 0;
				for (j = 1; j < prime[p]; ++j) {
					ans += pow(j, i);
				}
				ans = ans % prime[p];
				printf("num%d: %d\n", i, ans);
			}
		}
	}
	return 0;
}

