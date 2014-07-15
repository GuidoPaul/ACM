/*************************************************************************
	> File Name: G.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月15日 星期二 12时30分00秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

struct node {
	int x, y, step;
} data[10010], temp, now;
int dir[4][2] = {0, -1, -1, 0, 0, 1, 1, 0};
int visit[110][110];
int n, m;
char ch[110][110];

int inmap(int x, int y) {
	if(x >= 1 && x <= n && y >= 1 && y <= m)
		return 1;
	return 0;
}

void bfs(int stx, int sty) {
	int front = 0, rear = 1;
	int i;
	data[front].x = stx;
	data[front].y = sty;
	ch[stx][sty] = 'B';
	/* data[front].step = 1; */
	/* printf("%d %d %d\n", stx, sty, visit[stx][sty]); */
	visit[stx][sty] = 1;
	while(front < rear) {
		temp = data[front++];
		/* if(temp.x == edx && temp.y == edy) { */
			/* return temp.step; */
		/* } */
		for (i = 0; i < 4; ++i) {
			now.x = temp.x + dir[i][0];
			now.y = temp.y + dir[i][1];
		/* printf("%d %d %c**\n", now.x, now.y, ch[now.x][now.y]); */
			if(inmap(now.x, now.y) && ch[now.x][now.y] == '.' && visit[now.x][now.y] == 0) {
				visit[now.x][now.y] = 1;
				/* now.step = temp.step + 1; */
		/* printf("*****%c\n", ch[temp.x][temp.y]); */
				if(ch[temp.x][temp.y] == 'B') {
					ch[now.x][now.y] = 'W';
				} else {
					ch[now.x][now.y] = 'B';
				}
				data[rear++] = now;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int i, j;
	while(scanf("%d%d", &n, &m) != EOF) {
		getchar();
	memset(visit, 0, sizeof(visit));
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				scanf("%c", &ch[i][j]);
			}
			getchar();
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				if(ch[i][j] == '-') {
					continue;
				} else {
					if(visit[i][j] == 0) {
						bfs(i, j);
					}
				}
			}
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				printf("%c", ch[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

