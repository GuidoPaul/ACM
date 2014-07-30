/*************************************************************************
	> File Name: hdu4864.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月23日 星期三 18时40分14秒
 ************************************************************************/

#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 100010

struct node {
	int time, level;

	bool operator < (const node &b) const {
		if(time == b.time) {
			return level > b.level;
		}
		return time > b.time;
	}
} mach[N], task[N];
int vis[110];

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, i, j, k;
	long long ans, num;
	while(scanf("%d%d", &n, &m) != EOF) {
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &mach[i].time, &mach[i].level);
		}
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &task[i].time, &task[i].level);
		}
		sort(mach, mach + n);
		sort(task, task + m);
		memset(vis, 0, sizeof(vis));
		ans = 0;
		num = 0;
		for (i = 0, j = 0; i < m; ++i) {
			while(j < n && mach[j].time >= task[i].time) {
				vis[mach[j].level] ++;
				j ++;
			}
			for (k = task[i].level; k <= 100; ++k) {
				if(vis[k]) {
					num ++;
					vis[k] --;
					ans += 500 * task[i].time + 2 * task[i].level;
					break;
				}
			}
		}
		printf("%I64d %I64d\n", num, ans);
	}
	return 0;
}
