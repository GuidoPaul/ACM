/*************************************************************************
	> File Name: B.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月02日 星期六 12时04分30秒
 ************************************************************************/

#include <cstdio>
#include <string.h>
using namespace std;

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	char str[110];
	int num1, num2, num3, numj, len, i;
	while(scanf("%s", str) != EOF) {
		len = strlen(str);
		num1 = num2 = num3 = 0;
		numj = 0;
		for (i = 0; i < len; ++i) {
			if(str[i] == '1') {
				num1 ++;
			} else if(str[i] == '2') {
				num2 ++;
			} else if(str[i] == '3') {
				num3 ++;
			} else if(str[i] == '+') {
				numj ++;
			}
		}
		int j = 0;
		for (i = 0; i < num1 && j < numj; ++i, ++j) {
			printf("1+");
		}
		if(i < num1) printf("1");
		for (i = 0; i < num2 && j < numj; ++i, ++j) {
			printf("2+");
		}
		if(i < num2) printf("2");
		for (i = 0; i < num3 && j < numj; ++i, ++j) {
			printf("3+");
		}
		if(i < num3) printf("3");
		printf("\n");
	}
	return 0;
}
