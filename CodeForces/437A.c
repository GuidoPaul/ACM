/*************************************************************************
	> File Name: A.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年06月02日 星期一 10时10分44秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	freopen("in.txt", "r", stdin);
	char strA[110], strB[110], strC[110], strD[110];
	int lenA, lenB, lenC, lenD;
	int flag;

	while(scanf("%s%s%s%s", strA, strB, strC, strD) != EOF) {
		/* printf("%s %s %s %s\n", strA, strB, strC, strD); */
		lenA = strlen(strA) - 2;
		lenB = strlen(strB) - 2;
		lenC = strlen(strC) - 2;
		lenD = strlen(strD) - 2;
		flag = 0;
		if((lenA * 2 <= lenB && lenA * 2 <= lenC && lenA * 2 <= lenD) || (lenA >= lenB * 2 && lenA >= lenC * 2 && lenA >= lenD * 2)) {
			flag += 1;
		}
		if((lenB * 2 <= lenA && lenB * 2 <= lenC && lenB * 2 <= lenD) || (lenB >= lenA * 2 && lenB >= lenC * 2 && lenB >= lenD * 2)) {
			flag += 2;
		}
		if((lenC * 2 <= lenA && lenC * 2 <= lenB && lenC * 2 <= lenD) || (lenC >= lenA * 2 && lenC >= lenB * 2 && lenC >= lenD * 2)) {
			flag += 4;
		}
		if((lenD * 2 <= lenA && lenD * 2 <= lenB && lenD * 2 <= lenC) || (lenD >= lenA * 2 && lenD >= lenB * 2 && lenD >= lenC * 2)) {
			flag += 8;
		}
		if(flag == 1) {
			printf("A\n");
		} else if(flag == 2) {
			printf("B\n");
		} else if(flag == 4) {
			printf("C\n");
		} else if(flag == 8) {
			printf("D\n");
		} else {
			printf("C\n");
		}
	}
	return 0;
}
