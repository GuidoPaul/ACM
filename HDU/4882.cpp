/*************************************************************************
	> File Name: 11.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月24日 星期四 12时26分47秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100010

struct node {
	int a, b;
	double c;
	bool operator < (const node &b) const {
		return c < b.c;
	}
} num[N];

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, i;
	long long ans, now;
	while(scanf("%d", &n) != EOF) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &num[i].a);
		}
		for (i = 0; i < n; ++i) {
			scanf("%d", &num[i].b);
			num[i].c = (double)num[i].a / num[i].b;
		}
		sort(num, num + n);
		ans = 0;
		now = 0;
		for (i = 0; i < n; ++i) {
			ans += (now + num[i].a) * num[i].b;
			now = now + num[i].a;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
