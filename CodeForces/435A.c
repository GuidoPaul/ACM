#include <stdio.h>
int main() {
	int n, m, i, j;
	int now;
	int a[110];
	while(scanf("%d%d", &n, &m) != EOF) {
		for	(i = 0; i < n; i ++) {
			scanf("%d", &a[i]);
		}
		int ans = 0;
		for (i = 0; i < n;) {
			ans ++;
			now = m;
			while(now >= a[i]) {
				now -= a[i];
				i ++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
