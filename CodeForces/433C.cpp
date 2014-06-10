/*************************************************************************
	> File Name: C.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年06月10日 星期二 16时05分42秒
 ************************************************************************/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define M 100010

int a[M];
vector<int> v[M];

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, i, j;
	int cnt, temp;
	long long ans, sum, tempsum;
	while(scanf("%d%d", &n, &m) != EOF) {
		for (i = 1; i <= n; i++) {
			v[i].clear();
		}
		sum = 0;
		scanf("%d", &a[0]);
		for (i = 1; i < m; i++) {
			scanf("%d", &a[i]);
			if(a[i] != a[i-1]) {
				v[a[i]].push_back(a[i-1]);
				v[a[i-1]].push_back(a[i]);
			}
			sum += abs(a[i] - a[i-1]);
		}
		ans = sum;
		for (i = 1; i <= n; i++) {
			cnt = v[i].size();
			if(cnt == 0)
				continue;
			sort(v[i].begin(), v[i].end());
			temp = v[i][cnt / 2];
			tempsum = sum;
			for (j = 0; j < cnt; j++) {
				tempsum += (abs(temp - v[i][j]) - abs(i - v[i][j]));
			}
			if(tempsum < ans)
				ans = tempsum;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
