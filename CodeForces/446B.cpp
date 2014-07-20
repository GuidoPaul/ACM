/*************************************************************************
	> File Name: cf446B.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月15日 星期二 20时56分53秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define M 1010
#define N 1000010

struct node {
	long long x;  
	bool operator < (const node &a) const {  
		return a.x > x;  
	}  
} temp;

long long a, sumrow[M], sumcol[M], row[N], col[N];

long long max(long long a, long long b) {
	return a > b ? a : b;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, k, p, i, j;
	long long ans, temp;
	while(scanf("%d%d%d%d", &n, &m, &k, &p) != EOF) {
		memset(sumrow, 0, sizeof(sumrow));
		memset(sumcol, 0, sizeof(sumcol));
		priority_queue<long long> qr;
		priority_queue<long long> qc;
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				scanf("%lld", &a);
				sumrow[i] += a;
				sumcol[j] += a;
			}
		}
		for (i = 1; i <= n; ++i) {
			qr.push(sumrow[i]);
		}
		for (i = 1; i <= m; ++i) {
			qc.push(sumcol[i]);
		}
		row[0] = col[0] = 0;
		for (i = 1; i <= k; ++i) {
			temp = qr.top();
			qr.pop();
			row[i] = row[i - 1] + temp;
			temp -= m * p;
			qr.push(temp);
			temp = qc.top();
			qc.pop();
			col[i] = col[i - 1] + temp;
			temp -= n * p;
			qc.push(temp);
		}
		ans = max(row[k], col[k]);
		for (i = 1; i <= k; ++i) {
			ans = max(ans, row[i] + col[k - i] - (long long)1 * i * (k - i) * p);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
