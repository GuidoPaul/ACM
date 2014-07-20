/*************************************************************************
	> File Name: E.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月17日 星期四 12时20分27秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, s, i;
	int a[110], sum;
	while(scanf("%d%d", &n, &s) != EOF) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		sum = 0;
		for (i = 0; i < n - 1; ++i) {
			sum += a[i];
		}
		if(sum > s) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
}
