/*************************************************************************
	> File Name: B.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月15日 星期二 09时17分28秒
 ************************************************************************/

#include <cstdio>
using namespace std;
#define M 2010

struct node {
	int diff;
	int fa;
	int rank;
} bug[M];

int getfa(int x) {
	while(x != bug[x].fa) {
		x = bug[x].fa;
	}
	return x;
}

void Union(int a, int b) {
	if(bug[a].rank == bug[b].rank) {
		bug[a].rank ++;
		bug[b].fa = a;
	} else if(bug[a].rank > bug[b].rank) {
		bug[b].fa = a;
	} else {
		bug[a].fa = b;
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, n, m, i;
	int a, b;
	bool flag;
	int k;
	scanf("%d", &cas);
	for (k = 1; k <= cas; ++k) {
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; ++i) {
			bug[i].diff = 0;
			bug[i].fa = i;
			bug[i].rank = 1;
		}
		flag = 0;
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &a, &b);
			a = getfa(a);
			b = getfa(b);
			if(a == b) {
				flag = 1;
			} else {
				if(bug[a].diff == 0) {
					bug[a].diff = b;
				} else {
					Union(getfa(bug[a].diff), b);
				}
				if(bug[b].diff == 0) {
					bug[b].diff = a;
				} else {
					Union(getfa(bug[b].diff), a);
				}
			}
		}
		printf("Scenario #%d:\n", k);
		if(flag) {
			printf("Suspicious bugs found!\n");
		} else {
			printf("No suspicious bugs found!\n");
		}
		printf("\n");
	}
	return 0;
}
