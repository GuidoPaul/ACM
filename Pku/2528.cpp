/*************************************************************************
	> File Name: poj2528.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月14日 星期一 11时33分14秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define M 10010

struct node {
	int id, num;
} data[2 * M];
struct tree {
	int L, R;
	int sum;
} tree[M << 4];
int dis[M * 2][2];
bool flag;

bool cmp(node a, node b) {
	return a.num < b.num;
}

void PushUP(int p) {
	tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

void build(int L, int R, int p) {
	tree[p].L = L;
	tree[p].R = R;
	tree[p].sum = 0;
	if(L == R) {
		return;
	}
	int mid = (L + R) >> 1;
	build(L, mid, p << 1);
	build(mid + 1, R, p << 1 | 1);
}

void update(int L, int R, int p) {
	if(L <= tree[p].L && R >= tree[p].R) {
		int temp = tree[p].R - tree[p].L + 1;
		if(tree[p].sum != temp) {
			flag = 1;
			tree[p].sum = temp;
		}
		return ;
	}
	if(tree[p].sum == tree[p].R - tree[p].L + 1) return ;
	int mid = (tree[p].L + tree[p].R) >> 1;
	if(mid >= R) update(L, R, p << 1);
	else if(mid + 1 <= L) update(L, R, p << 1 | 1);
	else {
		update(L, mid, p << 1);
		update(mid + 1, R, p << 1 | 1);
	}
	PushUP(p);
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, n, l, r, i;
	int now, hash;
	int ans;
	scanf("%d", &cas);
	while(cas --) {
		scanf("%d", &n);
		memset(dis, 0, sizeof(dis));
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &l, &r);
			data[i << 1].id = i + 1;  // 对 i 的处理为了解决 i = 0 的情况
			data[i << 1].num = l;
			data[i << 1 | 1].id = -(i + 1);
			data[i << 1 | 1].num = r;
		}
		sort(data, data + 2 * n, cmp);  // 离散化,排序+映射
		now = 0;
		hash = 0;
		for (i = 0; i < 2 * n; ++i) {
			if(data[i].id > 0) {
				if(now != data[i].num) {
					hash ++;
					if(now + 1 != data[i].num)  // 加大一个距离
						hash ++;
				} 
				dis[data[i].id - 1][0] = hash;
			} else {
				if(now != data[i].num) {
					hash ++;
					if(now + 1 != data[i].num)
						hash ++;
				} 
				dis[-data[i].id - 1][1] = hash;
			}
			now = data[i].num;
		}
		build(1, hash, 1);
		ans = 0;
		for (i = n - 1; i >= 0; i--) {
			flag = 0;
			update(dis[i][0], dis[i][1], 1);
			if(flag) ans ++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
