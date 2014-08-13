/*************************************************************************
	> File Name: 4930.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月08日 星期五 09时48分48秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char str[2][20];
int player[2][20];

int hash(char ch) {
	if(ch >= '3' && ch <= '9') return ch - '3';
	switch(ch) {
		case 'T': return 7;
		case 'J': return 8;
		case 'Q': return 9;
		case 'K': return 10;
		case 'A': return 11;
		case '2': return 12;
		case 'X': return 13;
		case 'Y': return 14;
	}
}

int check(int idx, int num) {
	int len, i;
	for (i = 0; i <= 14; ++i) {
		if(player[idx][i] == num) {
			return 1;
		}
	}
	return 0;
}

int oneHand(int len) {
	if(len == 1) {
		return 1;
	}
	if(len == 2 && check(0, 2)) {
		return 1;
	}
	if(len == 3 && check(0, 3)) {
		return 1;
	}
	if(len == 4 && (check(0, 3) || check(0, 4))) {
		return 1;
	}
	if(len == 5 && (check(0, 3) && check(0, 2))) {
		return 1;
	}
	if(len == 6 && check(0, 4)) {
		return 1;
	}
	return 0;
}

int check1to3(int ll, int num) {
	int i;
	for (i = ll; i >= 0; --i) {
		if(player[0][i] >= num) return 1;
		if(player[1][i] >= num) return 0;
	}
	return 0;
}

int checkwith(int num1, int num2) {
	int i, j;
	for (i = 12; i >= 0; --i) {
		if(player[0][i] == num1) {
			for (j = 0; j <= 14; ++j) {
				if(i == j) continue;
				if(player[0][j] >= num2) {
					return 1;
				}
			}
		}
		if(player[1][i] == num1) {
			for (j = 0; j <= 14; ++j) {
				if(i == j) continue;
				if(player[1][j] >= num2) {
					return 0;
				}
			}
		}
	}
	return 0;
}

int iswin() {
	int i;
	if(player[0][13] && player[0][14]) return 1;  // 王炸
	if(player[1][13] && player[1][14]) return 0;
	for (i = 12; i >= 0; --i) {
		if(player[0][i] == 4) return 1;  // 4炸
		if(player[1][i] == 4) return 0;
	}
	for (i = 1; i <= 3; ++i) {
		if(check1to3(14, i)) {
			return 1;
		}
	}
	if(checkwith(3, 2) || checkwith(3, 1) || checkwith(4, 2)) {
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, len1, len2, i;
	int flag;
	scanf("%d", &cas);
	while(cas--) {
		scanf("%s", str[0]);
		scanf("%s", str[1]);
		len1 = strlen(str[0]);
		len2 = strlen(str[1]);
		memset(player, 0, sizeof(player));
		for (i = 0; i < len1; ++i) {
			player[0][hash(str[0][i])] ++;
		}
		for (i = 0; i < len2; ++i) {
			player[1][hash(str[1][i])] ++;
		}
		if(len1 <= 6 && oneHand(len1)) {  // 一手出完
			printf("Yes\n");
			continue;
		}
		if(iswin()) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
