/*************************************************************************
	> File Name: 436A.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年06月16日 星期一 11时27分04秒
	> 题意：有小怪兽要吃糖，糖是挂房顶的，有一定高度，小怪兽会跳起来吃到糖，
		而且吃了糖之后会跳的更高。但小怪兽有个癖好，不会同时吃同一类型的
		糖果。具体参数见输入输出样例。
	> 思路：在小怪兽能吃到的范围內，要尽量吃权重较大的糖果（会使它跳的更高）。
		由于只有两种类型的糖果，因此吃糖果的方式也就只有两种（先吃水果糖
		再吃焦糖，或者先吃焦糖再吃水果糖）。
	> 注意：1）当操作完第一种方式后，数据会被更新（如我代码中的data[].t），因
		此需要两组data来保存数据。
		2）当操作完第一种方式后，注意初始的 x 不要被改动。
		3）重复查找时由于循环的地方有 i++，因此调整 i = -1;
		4）排序方式采用权重大的（主）、高度低的（次）在前。
 ************************************************************************/

#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

struct node {
	int t, h, m;
} data0[2010], data1[2010];

bool cmp(node a, node b) {
	if(a.m == b.m)
		return a.h < b.h;
	return a.m > b.m;
}

int check(int n, int x, int type, node data[2010]) {
	int i, ans = 0;
	for (i = 0; i < n; i++) {
		if(data[i].t == type && data[i].h <= x) {
			data[i].t = -1;
			x += data[i].m;
			ans ++;
			type = 1 - type;
			i = -1;  // 重复查找
		}
	}
	return ans;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, x;
	int t, h, m, i;
	int ans;
	scanf("%d%d", &n, &x);
	for (i = 0; i < n; i++) {
		scanf("%d%d%d", &t, &h, &m);
		data0[i].t = data1[i].t = t;
		data0[i].h = data1[i].h = h;
		data0[i].m = data1[i].m = m;
	}
	sort(data0, data0 + n, cmp);
	sort(data1, data1 + n, cmp);
	ans = check(n, x, 0, data0);
	ans = max(ans, check(n, x, 1, data1));
	printf("%d\n", ans);
	return 0;
}
