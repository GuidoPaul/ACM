/*************************************************************************
	> File Name: hdu4940.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月12日 星期二 23时10分29秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

// If such set(Y < X) doesn’t exist, print “happy”,
// else print “unhappy”.
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int cas, n, m, i;
	int u, v, D, B;
	int X[210], Y[210];
	int kk = 1;
	scanf("%d", &cas);
	while(cas --) {
		scanf("%d%d", &n, &m);
		memset(X, 0, sizeof(X));
		memset(Y, 0, sizeof(Y));
		for (i = 0; i < m; ++i) {
			scanf("%d%d%d%d", &u, &v, &D, &B);
			X[u] += D;
			Y[v] += D + B;
		}
		for (i = 1; i <= n; ++i) {
			if(Y[i] < X[i]) {
				break;
			}
		}
		if(i > n) {
			printf("Case #%d: happy\n", kk ++);
		} else {
			printf("Case #%d: unhappy\n", kk ++);
		}
	}
	return 0;
}
