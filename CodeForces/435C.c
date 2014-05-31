#include <stdio.h>
#include <string.h>

char data[2010][1010];

int min(int a, int b) {
	return a > b ? b : a;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	freopen("in.txt", "r", stdin);
	int n, a, i, j;
	int nowx, nowy, sum, up, down;
	while(scanf("%d", &n) != EOF) {
		memset(data, 0, sizeof(data));
		nowx = 1000;
		nowy = 0;
		sum = 0;
		up = 1000;
		down = 1000;
		for (i = 0; i < n; i++) {
			scanf("%d", &a);
			sum += a;
			if(i % 2 == 0) {
				while(a != 0) {
					data[nowx][nowy] = '/';
					nowx --;
					nowy ++;
					a --;
				}
				nowx ++;
				up = min(up, nowx);
			} else {
				while(a != 0) {
					data[nowx][nowy] = '\\';
					nowx ++;
					nowy ++;
					a --;
				}
				nowx --;
				down = max(down, nowx);
			}
		}
		for (i = up; i <= down; i++) {
			for (j = 0; j < sum; j++) {
				if(data[i][j] != 0) {
					printf("%c", data[i][j]);
				} else {
					printf(" ");
				}
			}
			printf("\n");
		}
		/* printf("%d %d\n", up, down); */
	}
	return 0;
}
/*
5
3 1 2 5 1
3
1 5 1
5
5 4 3 2 1
*/
