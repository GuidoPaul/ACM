/*************************************************************************
	> File Name: H.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月19日 星期六 12时39分38秒
 ************************************************************************/

#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

struct node {
	char name[20];
	int id;
	int value;
	int vis;
} user[1100];

bool cmp(node a, node b) {
	if(a.value == b.value) {
		return a.id < b.id;
	}
	return a.value < b.value;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, n, i, j, k;
	char op[5];
	int cnt, value, pos, num;
	scanf("%d", &cas);
	for (k = 1; k <= cas; ++k) {
		printf("Case #%d:\n", k);
		scanf("%d", &n);
		cnt = 0;
		num = 0;
		for (i = 0; i < n; ++i) {
			scanf("%s", op);
			if(!strcmp(op, "Add")) {
				scanf("%s%d", &user[cnt].name, &user[cnt].value);
				user[cnt].id = i;
				user[cnt].vis = 0;
				cnt ++;
				num ++;
				printf("%d\n", num);
			} else if(!strcmp(op, "Find")) {
				scanf("%d", &value);
				sort(user, user + cnt, cmp);
				for (j = 0; j < cnt; ++j) {
					if(user[j].value >= value && user[j].vis == 0) {
						printf("%s\n", user[j].name);
						user[j].vis = 1;
						num --;
						break;
					}
				}
				if(j >= cnt) {
					printf("WAIT...\n");
				}
			}
		}
	}
	return 0;
}
