/*************************************************************************
	> File Name: poj1703.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月14日 星期一 19时43分19秒
 ************************************************************************/

#include <stdio.h>
#define M 100010

struct node {
	int diff, fa;
	int rank;
} gang[M];

int getfa(int x) {
	while(x != gang[x].fa) {
		x = gang[x].fa;
	}
	return x;
}

void Union(int x, int y) {
	if (gang[x].rank == gang[y].rank) {
		gang[x].rank ++;
		gang[y].fa = x;
	} else if(gang[x].rank > gang[y].rank){
		gang[y].fa = x;
	} else {
		gang[x].fa = y;
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, n, m, i;
	char op[2];
	int a, b;
	scanf("%d", &cas);
	while(cas--) {
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; ++i) {
			gang[i].diff = 0;
			gang[i].fa = i;
			gang[i].rank = 1;
		}
		for (i = 0; i < m; ++i) {
			scanf("%s%d%d", op, &a, &b);
			a = getfa(a);
			b = getfa(b);
			if(op[0] == 'A') {
				if(n == 2) {
					printf("In different gangs.\n");
				} else if(getfa(gang[a].diff) == b) {
					printf("In different gangs.\n");
				} else if(getfa(gang[b].diff) == a) {
					printf("In different gangs.\n");
				} else if(a == b) {
					printf("In the same gang.\n");
				} else {
					printf("Not sure yet.\n");
				}
			} else {
				if(gang[a].diff == 0) {
					gang[a].diff = b;
				} else {
					Union(getfa(gang[a].diff), b);
				}
				if(gang[b].diff == 0) {
					gang[b].diff = a;
				} else {
					Union(getfa(gang[b].diff), a);
				}
			}
		}
	}
	return 0;
}
