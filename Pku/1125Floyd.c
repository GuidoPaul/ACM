/*************************************************************************
	> File Name: 1125.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年06月01日 星期日 10时51分54秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define inf 0x1f

int dist[110][110];

void floyd(int n) {
	int k, i, j;
	int mindis, maxdis, minpos;
	for(k = 1; k <= n; k ++) {
		for(i = 1; i <= n; i ++) {
			for(j = 1; j <= n; j ++) {
				if(i != j && dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	mindis = inf;
	minpos = -1;
	for (i = 1; i <= n; i++) {
		maxdis = 0;
		for (j = 1; j <= n; j++) {
			if(i != j && maxdis < dist[i][j]) {
				maxdis = dist[i][j];
			}
		}
		if(mindis > maxdis) {
			mindis = maxdis;
			minpos = i;
		}
	}
	if(mindis >= inf) {
		printf("disjoint\n");
	} else {
		printf("%d %d\n", minpos, mindis);
	}

}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, i, j;
	int v, time;
	while(scanf("%d", &n), n != 0) {
		memset(dist, inf, sizeof(dist));
		/* printf("%d\n", dist[0][0]); */
		for (i = 1; i <= n; i++) {
			scanf("%d", &m);
			for (j = 1; j <= m; j++) {
				scanf("%d%d", &v, &time);
				dist[i][v] = time;
			}
		}
		floyd(n);
	}
	return 0;
}
