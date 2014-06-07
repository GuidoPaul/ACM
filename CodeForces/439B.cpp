/*************************************************************************
	> File Name: B.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年06月07日 星期六 22时52分39秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
using namespace std;
#define M	100010

long long a[M];

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, i;
	long long ans, x;
	while(scanf("%d%lld", &n, &x) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		ans = 0;
		for (i = 0; i < n; i++) {
			if(x != 1) {
				ans += x * a[i];
				x --;
			} else {
				ans += a[i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
