/*************************************************************************
	> File Name: CC.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月02日 星期六 15时02分11秒
 ************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int i, j, m;
	char str[20];
	int num[20], st1, st2, cnt, flag;
	int data[1010], now[2], k, cha;
	while(scanf("%s", str) != EOF) {
		st1 = st2 = 0;
		cnt = 0;
		for (i = 0; i < 10; ++i) {
			if(str[i] == '1') {
				num[cnt++] = i + 1;
			}
		}
		/* printf("cnt:%d\n", cnt); */
		scanf("%d", &m);
		if(cnt == 0) {
			printf("NO\n");
		} else if(m == 1) {
			printf("YES\n");
			printf("%d\n", num[0]);
		} else if(m == 2) {
			if(cnt >= 2) {
				printf("YES\n");
				printf("%d %d\n", num[0], now[1]);
			} else {
				printf("NO\n");
			}
		} else {
			if(cnt == 1) {
				printf("NO\n");
			} else {
				flag = 0;
				data[0] = num[cnt - 2], data[1] = num[cnt - 1];
				now[0] = data[0], now[1] = data[1];
				for (i = 2; i < m; ++i) {
					for (j = 0; j < cnt; ++j) {
						if(num[j] != data[i - 1] && num[j] + now[i & 1] > now[1 - (i & 1)]) {
							data[i] = num[j];
							now[i & 1] += num[j];
							break;
						}
					}
					if(j >= cnt) {
						if(flag == 0) {
							flag = 1;
							break;
						}
					}
				}
				/* printf("flag:%d %d\n", flag, m); */
				if(flag == 1) {
					data[0] = num[0], data[1] = num[cnt - 2];
					if(data[0] == data[1]) data[1] = num[cnt - 1];
					now[0] = data[0], now[1] = data[1];
					for (i = 2; i < m; ++i) {
						for (j = 0; j < cnt; ++j) {
							if(num[j] != data[i - 1] && num[j] + now[i & 1] > now[1 - (i & 1)]) {
								data[i] = num[j];
								now[i & 1] += num[j];
								break;
							}
						}
						if(j >= cnt) {
							if(flag == 1) {
								flag = 2;
								break;
							}
						}
					}
					if(flag == 2) {
						printf("NO\n");
					} else {
						printf("YES\n");
						for (i = 0; i < m; ++i) {
							if(i != m - 1) printf("%d ", data[i]);
							else printf("%d\n", data[i]);
						}
					}
				} else {
					printf("YES\n");
					for (i = 0; i < m; ++i) {
						if(i != m - 1) printf("%d ", data[i]);
						else printf("%d\n", data[i]);
					}
				}
			}
		}
	}
	return 0;
}
