/*************************************************************************
	> File Name: cf446A.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月15日 星期二 20时04分32秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define M 100010

int a[M];

struct node {
	int en1, en2;
	int st1, st2;
	int cnt;
} data[M];

int max(int a, int b) {
	return a > b ? a : b;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, i;
	int k;
	int ans;
	while(scanf("%d", &n) != EOF) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		ans = 0;
		k = 0;
		data[k].cnt = 1;
		for (i = 0; i < n - 1; ++i) {
			if(a[i + 1] > a[i]) {
				data[k].cnt ++;
			} else {
				if(data[k].cnt >= 2) {
					data[k].st1 = a[i - data[k].cnt + 1];
					data[k].st2 = a[i - data[k].cnt + 2];
					data[k].en1 = a[i - 1];
					data[k].en2 = a[i];
				}
				data[++k].cnt = 1;
			}
		}
		if(data[k].cnt >= 2) {
			data[k].st1 = a[i - data[k].cnt + 1];
			data[k].st2 = a[i - data[k].cnt + 2];
			data[k].en1 = a[i - 1];
			data[k].en2 = a[i];
		}
		ans = 1;
		for (i = 0; i <= k; ++i) {
			if(k == 0)
				ans = max(ans, data[i].cnt);
			else
				ans = max(ans, data[i].cnt + 1);
			if(i + 1 <= k && data[i].cnt >= 2 && data[i+1].cnt >= 2) {
				if(data[i].en2 + 2 <= data[i+1].st2) {
					ans = max(ans, data[i].cnt + data[i+1].cnt);
				}
				if(data[i].en1 + 2 <= data[i+1].st1) {
					ans = max(ans, data[i].cnt + data[i+1].cnt);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
