/*************************************************************************
  > File Name: 10102.c
  > Author: Bslin
  > Mail: Baoshenglin1994@gmail.com
  > Created Time: 2014年08月05日 星期二 14时18分00秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 810
#define MOD 3

int v1[N][N], v2[N][N], v3[N][N];
int n;

int nextInt() {
	char ch;
	int res = 0;
	while(ch = getchar(), !isdigit(ch));
	do {
		res = (res << 3) + (res << 1) + (ch - '0');
	} while(ch = getchar(), isdigit(ch));
	return res;
}

void mul(int n) {
	int i, j, k;
	memset(v3, 0, sizeof(v3));
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if(v1[i][j] == 0) continue;
			for (k = 0; k < n; ++k) {
				v3[i][k] = (v3[i][k] + v1[i][j] * v2[j][k]) % MOD;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int i, j;
	while(scanf("%d", &n) != EOF) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				v1[i][j] = nextInt();
				v1[i][j] %= MOD;
			}
		}
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				v2[i][j] = nextInt();
				v2[i][j] %= MOD;
			}
		}
		mul(n);
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				if(j == 0) printf("%d", v3[i][j] % MOD);
				else printf(" %d", v3[i][j] % MOD);
			}
			printf("\n");
		}
	}
	return 0;
}

