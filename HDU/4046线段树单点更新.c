/*************************************************************************
	> File Name: D.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月19日 星期六 16时11分34秒
 ************************************************************************/

#include <stdio.h>
#define M 50010

struct node {
	int L, R;
	int num;
	char ml, mm, mr;
} tree[M << 2];

int ans, n, m;
char str[M];

void PushUP(int p) {
	tree[p].num = tree[p << 1].num + tree[p << 1 | 1].num;
}

void build(int L, int R, int p) {
	tree[p].L = L;
	tree[p].R = R;
	if (L == R) {
		if(L - 2 >= 0)
			tree[p].ml = str[L - 2];
		else
			tree[p].ml = '$';
		tree[p].mm = str[L - 1];
		if(L < n)
			tree[p].mr = str[L];
		else
			tree[p].mr = '$';
		if(tree[p].ml == 'w' && tree[p].mm == 'b' && tree[p].mr == 'w') {
			tree[p].num = 1;
		} else {
			tree[p].num = 0;
		}
		return ;
	}
	int mid = (L + R) >> 1;
	build(L, mid, p << 1);
	build(mid + 1, R, p << 1 | 1);
	PushUP(p);
}

void update(int pos, char ch, int p) {
	if(pos - 1 == tree[p].L && pos - 1 == tree[p].R) {
		tree[p].mr = ch;
		if(tree[p].ml == 'w' && tree[p].mm == 'b' && tree[p].mr == 'w') {
			tree[p].num = 1;
		} else {
			tree[p].num = 0;
		}
		return ;
	}
	if(pos == tree[p].L && pos == tree[p].R) {
		tree[p].mm = ch;
		if(tree[p].ml == 'w' && tree[p].mm == 'b' && tree[p].mr == 'w') {
			tree[p].num = 1;
		} else {
			tree[p].num = 0;
		}
		return ;
	}
	if(pos + 1 == tree[p].L && pos + 1 == tree[p].R) {
		tree[p].ml = ch;
		if(tree[p].ml == 'w' && tree[p].mm == 'b' && tree[p].mr == 'w') {
			tree[p].num = 1;
		} else {
			tree[p].num = 0;
		}
		return ;
	}
	int mid = (tree[p].L + tree[p].R) >> 1;
	if (mid >= pos + 1) update(pos, ch, p << 1);
	else if (mid + 1 <= pos - 1) update(pos, ch, p << 1 | 1);
	else {
		update(pos, ch, p << 1);
		update(pos, ch, p << 1 | 1);
	}
	PushUP(p);
}

void query(int L, int R, int p) {
	if (L <= tree[p].L && R >= tree[p].R) {
		ans += tree[p].num;
		return ;
	}
	int mid = (tree[p].L + tree[p].R) >> 1;
	if (mid >= R) query(L, R, p << 1);
	else if (mid + 1 <= L) query(L, R, p << 1 | 1);
	else {
		query(L, mid, p << 1);
		query(mid + 1, R, p << 1 | 1);
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, i, k;
	int op, a, b;
	char ch;
	scanf("%d", &cas);
	for (k = 1; k <= cas; ++k) {
		scanf("%d%d%s", &n, &m, str);
		printf("Case %d:\n", k);
		build(1, n, 1);
		for (i = 0; i < m; ++i) {
			scanf("%d", &op);
			if(op == 0) {
				scanf("%d%d", &a, &b);
				if(a + 2 > b) {
					printf("0\n");
					continue;
				}
				a += 2;  //
				/* b ++; */
				ans = 0;
				query(a, b, 1);
				printf("%d\n", ans);
			} else {
				scanf("%d %c", &a, &ch);
				a ++;
				update(a, ch, 1);
			}
		}
	}
	return 0;
}
