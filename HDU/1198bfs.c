/*************************************************************************
	> File Name: C.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月19日 星期六 12时16分48秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

struct node {
	int x, y;
} data[4000], temp, now;
int vis[60][60];
char map[60][60];
int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
int n, m;
int flag[15][4];

int inmap(int x, int y) {
	if(x >= 0 && x < n && y >= 0 && y < m)
		return 1;
	return 0;
}

int check(char ch1, char ch2, int d) {
	if(d == 0) {
		return flag[ch1-'A'][0] && flag[ch2-'A'][2];
	} else if(d == 1) {
		return flag[ch1-'A'][1] && flag[ch2-'A'][3];
	} else if(d == 2) {
		return flag[ch1-'A'][2] && flag[ch2-'A'][0];
	} else {
		/* printf("%d %d\n", ch1-'A', ch2-'A'); */
		return flag[ch1-'A'][3] && flag[ch2-'A'][1];
	}
}

void bfs(int stx, int sty) {
	int front = 0, rear = 1;
	int i;
	data[front].x = stx;
	data[front].y = sty;
	vis[stx][sty] = 1;
	while(front < rear) {
		temp = data[front++];
		for (i = 0; i < 4; ++i) {
			now.x = temp.x + dir[i][0];
			now.y = temp.y + dir[i][1];
			/* printf("nowx nowy %d %d %d\n", now.x, now.y, check(map[temp.x][temp.y], map[now.x][now.y], i)); */
			if(inmap(now.x, now.y) && check(map[temp.x][temp.y], map[now.x][now.y], i) && vis[now.x][now.y] == 0) {
				/* printf("%d %d %d %d %d\n", temp.x, temp.y, now.x, now.y, i); */
				vis[now.x][now.y] = 1;
				data[rear++] = now;
			}
		}
	}
}

void init() {
	memset(flag, 0, sizeof(flag));
	flag[0][0] = flag[0][1] = 1;
	flag[1][0] = flag[1][3] = 1;
	flag[2][1] = flag[2][2] = 1;
	flag[3][2] = flag[3][3] = 1;
	flag[4][0] = flag[4][2] = 1;
	flag[5][1] = flag[5][3] = 1;  // F
	flag[6][0] = flag[6][1] = flag[6][3] = 1;
	flag[7][0] = flag[7][1] = flag[7][2] = 1;  // H
	flag[8][1] = flag[8][2] = flag[8][3] = 1;
	flag[9][0] = flag[9][2] = flag[9][3] = 1;
	flag[10][0] = flag[10][1] = flag[10][2] = flag[10][3]= 1;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int i, j;
	int ans;
	init();
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == -1 && m == -1) {
			break;
		}
		getchar();
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				scanf("%c", &map[i][j]);
				/* printf("%c", map[i][j]); */
			}
			getchar();
			/* printf("\n"); */
		}
		memset(vis, 0, sizeof(vis));
		ans = 0;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				if(vis[i][j] == 0) {
					/* printf("%d %d\n", i, j); */
					bfs(i, j);
					ans ++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
