/*************************************************************************
	> File Name: C.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年06月09日 星期一 00时17分30秒
	> 题意：有 k 根最短 2 个格子长的管子，管子不可交叉在一起，放满这个矩阵格子（其他条件可看图得到）。
	> 思路：按照 S 型摆放管子，前面 k-1 根管子都为 2 个格子长，最后一根把剩余的格子填满（放心，它最短也是 2 个格子长，因为 2 ≤ 2k ≤ n·m），如果你超时了八九不离十是因为无限输出了，因为就算一个格子一个格子的输出，最多也是 300*300 的次数（对自己说的）。
 ************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, k;
	int i, j, nowc, nowr;
	int flag;
	while(scanf("%d%d%d", &n , &m, &k) != EOF) {
		nowr = 1, nowc = 1;
		flag = 1;  // flag = 1 从左往右, flag = 0 从右往左
		for (i = 1; i <= k - 1; i++) {
			printf("2");
			if(flag) {
				if(nowc == m) {
					printf(" %d %d %d %d\n", nowr, nowc, nowr + 1, nowc);
					flag = 1 - flag;
					nowr ++;
					nowc --;
				} else if(nowc == m + 1) {
					printf(" %d %d %d %d\n", nowr + 1, m, nowr + 1, m - 1);
					flag = 1 - flag;
					nowr ++;
					nowc = m - 2;
				} else {
					printf(" %d %d %d %d\n", nowr, nowc, nowr, nowc + 1);
					nowc += 2;
				}
			} else {
				if(nowc == 0) {
					printf(" %d %d %d %d\n", nowr + 1, 1, nowr + 1, 2);
					nowc = 3;
					nowr ++;
					flag = 1 - flag;
				} else {
					printf(" %d %d %d %d\n", nowr, nowc, nowr, nowc - 1);
					nowc -= 2;
				}
			}
		}
		int temp = n * m - 2 * (k - 1);
		printf("%d", temp);
		while(temp != 0) {
			if(flag) {
				if(nowc != m + 1) {
					printf(" %d %d", nowr, nowc);
					nowc += 1;
				} else {
					printf(" %d %d", nowr + 1, m);
					flag = 1 - flag;
					nowr ++;
					nowc -= 2;
				}
			} else {
				if(nowc != 0) {
					printf(" %d %d", nowr, nowc);
					nowc -= 1;
				} else {
					printf(" %d %d", nowr + 1, 1);
					nowr ++;
					nowc = 2;
					flag = 1 - flag;
				}
			}
			temp --;
		}
		printf("\n");
	}
	return 0;
}
