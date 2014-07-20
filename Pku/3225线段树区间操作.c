/*************************************************************************
	> File Name: poj3225.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月17日 星期四 16时48分11秒
 ************************************************************************/

#include <stdio.h>
#define M 131080

struct node {
	int L, R;
	int cover, turn;
} tree[M << 2];
int vis[M];

void change(int p) {
	if(tree[p].cover != -1) {
		tree[p].cover = 1 - tree[p].cover;
	} else {
		tree[p].turn = 1 - tree[p].turn;
	}
}

void PushDown(int p) {
	if(tree[p].cover != -1) {
		tree[p << 1].cover = tree[p << 1 | 1].cover = tree[p].cover;
		tree[p << 1].turn = tree[p << 1 | 1].turn = 0;
		tree[p].cover = -1;  // 将覆盖结果交给左右孩子
	}
	if(tree[p].turn) {
		change(p << 1);
		change(p << 1 | 1);
		tree[p].turn = 0;
	}
}

void build(int L, int R, int p) {
	tree[p].L = L;
	tree[p].R = R;
	if(L == R) {
		tree[p].cover = 0;
		tree[p].turn = 0;
		return ;
	}
	int mid = (L + R) >> 1;
	build(L, mid, p << 1);
	build(mid + 1, R, p << 1 | 1);
}

void update(int L, int R, char op, int p) {
	if(L <= tree[p].L && R >= tree[p].R) {
		if(op == 'U') {
			tree[p].cover = 1;
			tree[p].turn = 0;  // 注意
		} else if(op == 'D') {
			tree[p].cover = 0;
			tree[p].turn = 0;
		} else if(op == 'S' || op == 'C') {
			change(p);
		}
		return ;
	}
	PushDown(p);
	int mid = (tree[p].L + tree[p].R) >> 1;
	if (mid >= R) {
		if(op == 'C' || op == 'I') {
			tree[p << 1 | 1].cover = tree[p << 1 | 1].turn = 0;
		}
		update(L, R, op, p << 1);
	} else if (mid + 1 <= L) {
		if(op == 'C' || op == 'I') {
			tree[p << 1].cover = tree[p << 1].turn = 0;
		}
		update(L, R, op, p << 1 | 1);
	}
	else {
		update(L, mid, op, p << 1);
		update(mid + 1, R, op, p << 1 | 1);
	}
}

void query(int p) {
	if(tree[p].cover == 1) {
		int i;
		for (i = tree[p].L; i <= tree[p].R; ++i) {
			vis[i] = 1;
		}
		return ;
	} else if(tree[p].cover == 0) {
		return ;
	}
	PushDown(p);
	query(p << 1);
	query(p << 1 | 1);
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	char op, lk, rk;
	int ll, rr, i;
	int st, ed, flag;
	build(0, M, 1);
	while(scanf("%c %c%d,%d%c\n", &op, &lk, &ll, &rr, &rk) != EOF) {
		ll <<= 1;
		rr <<= 1;
		if(lk == '(') ll ++;
		if(rk == ')') rr --;
		if(ll <= rr) {
			update(ll, rr, op, 1);
		} else {  // 注意, 例如 (3,3)
			if(op == 'C' || op == 'I') {
				tree[1].cover = tree[1].turn = 0;
			}
		}
	}
	query(1);
	st = -1;
	flag = 0;
	for (i = 0; i < M; ++i) {
		if(vis[i]) {
			if(st == -1) st = i;
			ed = i;
		} else {
			if(st != -1) {
				if(flag != 0) {
					printf(" ");
				}
				flag = 1;
				if(st % 2 == 0) {
					printf("[%d,", st >> 1);
				} else {
					printf("(%d,", st >> 1);
				}
				if(ed % 2 == 0) {
					printf("%d]", ed >> 1);
				} else {
					printf("%d)", (ed + 1) >> 1);
				}
				st = -1;
			}
		}
	}
	if(flag == 0) {
		printf("empty set");
	}
	printf("\n");
	return 0;
}
