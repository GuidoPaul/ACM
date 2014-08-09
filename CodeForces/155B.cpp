/*************************************************************************
	> File Name: D.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月09日 星期六 12时22分19秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1010

struct node {
	int point, card;
	bool operator < (const node &b) const {
		if(card == b.card) return point > b.point;
		return card > b.card;
	}
} data[N];

int main(int argc, char *argv[]) {
	/* freopen("in.txt", "r", stdin); */
	int n, i;
	int num, ans;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d%d", &data[i].point, &data[i].card);
	}
	sort(data, data + n);
	num = 0;
	ans = 0;
	num = data[0].card;
	ans = data[0].point;
	for (i = 1; i < n; ++i) {
		if(num > 0) {
			num += data[i].card;
			ans += data[i].point;
		} else {
			break;
		}
		num --;
	}
	printf("%d\n", ans);
	return 0;
}
