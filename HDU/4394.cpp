/*************************************************************************
	> File Name: hdu4394.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月16日 星期六 18时50分30秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 0x7FFFFFFF

long long ans;

void dfs(long long val, long long w, long long sum) {
	long long i, tmp;
	/* printf("%d %d %d\n", val, w, sum); */
	if(val == 0) {
		ans = min(ans, sum);
		return ;
	}
	for (i = 0; i <= 9; ++i) {
		tmp = (i * w + sum);
		if((tmp * tmp / w) % 10 == val % 10) {
			dfs(val / 10, w * 10, tmp);
		}
	}
}

int main(int argc, char *argv[]) {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	int cas, n;
	scanf("%d", &cas);
	while(cas--) {
		scanf("%d", &n);
		ans = INF;
		/* printf("%lld\n", ans); */
		dfs(n, 1, 0);
		if(ans == INF) {
			printf("None\n");
		} else {
			printf("%I64d\n", ans);
		}
	}
	return 0;
}
