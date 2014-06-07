/*************************************************************************
	> File Name: C.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年06月07日 星期六 23时28分31秒

	//三种情况：
	//1、奇数不够: NO
	//2、奇数刚好
	//		1）偶数足够:YES
	//		2）偶数不够:NO
	//3、奇数足够
	//		设: temp = 奇数个数与(k-p)的差
	//		1）temp为奇数:NO
	//		2）temp为偶数
	//			1.temp/2 + 偶数个数 < p : NO
	//			2.temp/2 + 偶数个数 >= p : YES
	//
	//注意输出
 ************************************************************************/

#include <stdio.h>
#define M 100010

int n, k, p, cnta, cntb;
int a[M], b[M];

void printans() {
	int i, j, u;
	int temp;  // temp: 前 k-1 组中有多余两个1的组数
	if(p > cnta)
		temp = (cntb - ((p - cnta) * 2 + (k - p))) / 2;
	else
		temp = (cntb - (k - p)) / 2;
	printf("YES\n");
	/* printf("temp = %d\n", temp); */
	for (u = 0, i = 0, j = 0; u < k - 1; u++) {
		// 有多余两个1
		if(u < temp) {
			// 偶数和输出
			if(u < p) {
				if(i < cnta) {
					printf("3 %d %d %d\n", a[i], b[j], b[j+1]);
					i ++;
					j += 2;
				} else {
					printf("4 %d %d %d %d\n", b[j], b[j+1], b[j+2], b[j+3]);
					j += 4;
				}
			// 奇数和输出
			} else {
				printf("3 %d %d %d\n", b[j], b[j+1], b[j+2]);
				j += 3;
			}
		// 没有多余两个1
		} else {
			// 偶数和输出
			if(u < p) {
				if(i < cnta) {
					printf("1 %d\n", a[i]);
					i ++;
				} else {
					printf("2 %d %d\n", b[j], b[j+1]);
					j += 2;
				}	
			// 奇数和输出
			} else {
				printf("1 %d\n", b[j]);
				j ++;
			}
		}
	}
	temp = cnta - i + cntb - j;
	if(temp == 0) return;
	printf("%d", temp);
	while(i < cnta) {
		printf(" %d", a[i]);
		i ++;
	}
	while(j < cntb) {
		printf(" %d", b[j]);
		j ++;
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int x, i;

	while(scanf("%d%d%d", &n, &k, &p) != EOF) {
		cnta = cntb = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &x);
			// a 存偶数 , b 存奇数
			if(x % 2 == 0) {
				a[cnta++] = x;
			} else{
				b[cntb++] = x;
			}
		}
		if(cntb < (k - p)) {
			printf("NO\n");
		} else if(cntb == (k - p)) {
			if(cnta < p) {
				printf("NO\n");
			} else {
				printans();
			}
		} else {
			int temp = cntb - (k - p);
			if(temp % 2 == 1) {
				printf("NO\n");
			} else {
				if(temp / 2 + cnta < p) {
					printf("NO\n");
				} else {
					printans();
				}
			}
		}
	}
	return 0;
}
