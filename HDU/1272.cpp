/*************************************************************************
	> File Name: A.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月14日 星期一 21时05分48秒
 ************************************************************************/

#include <cstdio>
using namespace std;
#define M 100010

int fa[M], visit[M], flag;

int min(int a, int b) {
	return a > b ? b : a;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int getfa(int a) {
	while(a != fa[a]) {
		a = fa[a];
	}
	return a;
}

void Union(int a, int b) {
	a = getfa(a);
	b = getfa(b);
	if(a != b) {
		fa[a] = b;
	} else {
		flag = 0;
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int a, b, i;
	int cnt;
	while(scanf("%d%d", &a, &b)) {
		if(a == -1 && b == -1) {
			break;
		}
		if(a == 0 && b == 0) {
			printf("Yes\n");
		}
		for (i = 1; i < M; ++i) {
			fa[i] = i;
			visit[i] = 0;
		}
		fa[a] = b;
		visit[a] = visit[b] = 1;
		flag = 1;
		int min1 = M, max1 = -1;
		max1 = max(max1, max(a, b));
		min1 = min(min1, min(a, b));
		while(scanf("%d%d", &a, &b)) {
			if(a == 0 && b == 0) {
				break;
			}
			max1 = max(max1, max(a, b));
			min1 = min(min1, min(a, b));
			visit[a] = visit[b] = 1;
			Union(a, b);
		}
		if(flag == 0) {
			printf("No\n");
		} else {
			cnt = 0;
			for (i = min1; i <= max1; ++i) {
				if(visit[i] && fa[i] == i) {
					cnt ++;
				}
			}
			if(cnt == 1) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		}
	}
	return 0;
}
