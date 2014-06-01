/*************************************************************************
	> File Name: 2240.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年06月01日 星期日 11时20分43秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

struct node {
	int u, v;
	double cost;
} edge[1010];
double dis[1010];
int n, m;

bool Bellman_Ford() {
	bool flag;
	for(int i = 1; i <= n; ++i)
		dis[i] = 0;
	dis[1] = 1;

	for(int i = 1; i <= n - 1; ++i) {
		flag = 0;
		for(int j = 1; j <= m; ++j) {
			if(dis[edge[j].v] < dis[edge[j].u] * edge[j].cost) {
				dis[edge[j].v] = dis[edge[j].u] * edge[j].cost;
				flag = 1;
			}
		}
		if(flag == 0)
			break;
	}

	for(int i = 1; i <= m; ++i) {
		if(dis[edge[i].v] < dis[edge[i].u] * edge[i].cost)
			return true;
	}
	return false;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	string str1, str2;
	double transform;
	int i;
	map<string, int> mp;
	int cas = 1;
	while(scanf("%d", &n), n != 0) {
		mp.clear();
		for (i = 1; i <= n; i++) {
			cin >> str1;
			mp[str1] = i;
		}
		scanf("%d", &m);
		for (i = 1; i <= m; i++) {
			cin >> str1 >> transform >> str2;
			edge[i].u = mp[str1];
			edge[i].v = mp[str2];
			edge[i].cost = transform;
		}
		if(!Bellman_Ford()) {
			printf("Case %d: No\n", cas++);
		} else {
			printf("Case %d: Yes\n", cas++);
		}
	}
	return 0;
}
