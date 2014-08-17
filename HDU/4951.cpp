/*************************************************************************
	> File Name: hdu4951.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月15日 星期五 13时13分24秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

inline int getint() {
	int ret = 0, ch;
	bool ok = 0;
	while(1) {
		ch = getchar();
		if(ch >= '0' && ch <= '9') {
			ret = (ret << 3) + ret + ret + ch - '0', ok = 1;
		} else if(ok) {
			return ret;
		}
	}
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int n, i, j;
	int x, y;
	int vis1[510], vis2[510], cnt1, cnt2;
	int ans[510], kk = 1;
	while(1) {
		n = getint();
		if(n == 0) break;
		for (i = 0; i < n; ++i) {
			memset(vis1, 0, sizeof(vis1));
			memset(vis2, 0, sizeof(vis2));
			cnt1 = cnt2 = 0;
			for (j = 0; j < n; ++j) {
				x = getint();
				y = getint();
				if(!vis1[x]) {
					cnt1 ++;
					vis1[x] = 1;
				}
				if(!vis2[y]) {
					cnt2 ++;
					vis2[y] = 1;
				}
			}
			if(cnt1 == 1 && cnt2 == 1) {
				ans[0] = i;
			} else if(cnt1 == 1 && cnt2 == n) {
				ans[1] = i;
			} else {
				ans[cnt1] = i;
			}
		}
		printf("Case #%d:", kk++);
		for (i = 0; i < n; ++i) {
			printf(" %d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
