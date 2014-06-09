/*************************************************************************
	> File Name: 441B.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年06月08日 星期日 23时47分35秒
	> 题意：水果树上水果可以保存两天去摘，每天可以摘任意多棵，但每天可摘的能力有限，问最多能摘几个水果。
	> 思路：生成一个数组，数组里每个元素保存原本当天可摘的水果数(old)和前一天剩余的水果数(rem)，输入完成后遍历一遍到最大天数+1即可。（注意：是前一天剩余的水果，不是前面所有天数剩余的水果）
 ************************************************************************/

#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

struct node {
	int old, rem;
} data[3010];

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, v;
	int i, x, y, max;
	int ans;

	while(scanf("%d%d", &n, &v) != EOF) {
		max = 0;
		memset(data, 0, sizeof(data));
		for (i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			data[x].old += y;
			if(x > max)
				max = x;
		}
		data[max+1].old = 0;
		ans = 0;
		for (i = 1; i <= max + 1; i++) {
			if(data[i].old + data[i].rem >= v) {
				ans += v;
				if(v > data[i].rem) {
					data[i].old = data[i].old - (v - data[i].rem);
					data[i+1].rem += data[i].old;
				} else {
					data[i+1].rem += data[i].old;
				}
			} else {
				ans += data[i].old + data[i].rem;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
