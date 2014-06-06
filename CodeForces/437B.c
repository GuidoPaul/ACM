#include <stdio.h>

int ans[100010];

int main() {
	freopen("in.txt", "r", stdin);
	int sum, limit, now, cnt;
	int temp, i;
	while(scanf("%d%d", &sum, &limit) != EOF) {
		now = 1;
		cnt = 0;
		while(sum != 0 && limit >= 0) {
			temp = limit & (-limit);
			if(temp <= sum) {
				ans[cnt++] = limit;
				sum -= temp;
			}
			limit --;
		}
		if(limit >= 0) {
			printf("%d\n", cnt);
			for (i = 0; i < cnt; i++) {
				if(i == 0) printf("%d", ans[i]);
				else printf(" %d", ans[i]);
			}
			printf("\n");	
		} else {
			printf("-1\n");
		}
	}
	return 0;
}
