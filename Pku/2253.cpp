/*************************************************************************
	> File Name: 2253.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年05月31日 星期六 23时09分11秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#define INF 9999999
#define N 210

struct node {
	int x, y;
} stone[N];
int visit[N];
double cost[N][N], ans;

void dijkstra(int n, int beg) {
	int i, j, pre;
	double lowcost[N], min;

	memset(visit, 0, sizeof(visit));

	for (i = 0; i < n; i++) {
		lowcost[i] = cost[beg][i];
	}
	visit[beg] = 1;
	lowcost[beg] = 0;
	pre = beg;
	for (i = 1; i < n; i++) {
		min = INF;
		for (j = 0; j < n; j++) {
			if(visit[j] == 0 && cost[pre][j] < lowcost[j]) {
				lowcost[j] = cost[pre][j];
			}
		}
		for (j = 0; j < n; j++) {
			if (visit[j] == 0 && lowcost[j] < min) {
				min = lowcost[j];
				pre = j;
			}
		}
		if(ans < min) {
			ans = min;
		}
		if(pre == 1) return ;
		visit[pre] = 1;
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, x, y, i, j;
	int stx, sty, enx, eny, disx, disy;
	int cas = 1;
	while(scanf("%d", &n), n != 0) {
		for (i = 0; i < n; i++) {
			scanf("%d%d", &stone[i].x, &stone[i].y);
			for (j = 0; j < i; j++) {
				disx = stone[i].x - stone[j].x;
				disy = stone[i].y - stone[j].y;
				cost[i][j] = sqrt((double)disx * disx + (double)disy * disy);
				cost[j][i] = cost[i][j];
			}
		}
		ans = 0;
		dijkstra(n, 0);
		printf("Scenario #%d\n", cas++);
		printf("Frog Distance = %.3f\n\n", ans);
	}
	return 0;
}
