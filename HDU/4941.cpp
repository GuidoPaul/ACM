/*************************************************************************
	> File Name: hdu4941.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月12日 星期二 19时01分00秒
 ************************************************************************/

#include <cstdio>
#include <map>
using namespace std;
#define N 100010

map<int, int> row;
map<int, int> col;
map<int, map<int, int> > mp;

void init() {
	int i;
	row.clear();
	col.clear();
	mp.clear();
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int cas, n, m, k, i;
	int x, y, val, rr, ll;
	int t, op, A, B;
	int a, b;
	int kk = 1;
	scanf("%d", &cas);
	while(cas --) {
		scanf("%d%d%d", &n, &m, &k);
		init();
		rr = 0;
		ll = 0;
		for (i = 0; i < k; ++i) {
			scanf("%d%d%d", &x, &y, &val);
			if(!row[x]) {
				row[x] = ++rr;
				a = rr;
			} else {
				a = row[x];
			}
			if(!col[y]) {
				col[y] = ++ll;
				b = ll;
			} else {
				b = col[y];
			}
			mp[a][b] = val;
		}
		scanf("%d", &t);
		printf("Case #%d:\n", kk++);
		for (i = 0; i < t; ++i) {
			scanf("%d%d%d", &op, &A, &B);
			if(op == 1) {
				swap(row[A], row[B]);
			} else if(op == 2) {
				swap(col[A], col[B]);
			} else if(op == 3) {
				printf("%d\n", mp[row[A]][col[B]]);
			}
		}
	}
	return 0;
}
