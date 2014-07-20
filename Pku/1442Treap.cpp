/*************************************************************************
  > File Name: treapstruct.cpp
  > Author: Bslin
  > Mail: Baoshenglin1994@gmail.com
  > Created Time: 2014年07月18日 星期五 13时51分31秒
 ************************************************************************/

#include <stdio.h>
#include <cstdlib>
using namespace std;
#define M 30010

struct node {
	int l, r, key, rand_fix;
	int countl, countr;
} tree[M];
int size, root;
int a[M];

// left rotate  
void l_rotate(int &index) {
	int y = tree[index].r;
	tree[index].r = tree[y].l;
	tree[index].countr = tree[y].countl;
	tree[y].l = index;
	tree[y].countl = tree[index].countl + tree[index].countr + 1;
	index = y;
}

// right rotate
void r_rotate(int &index) {
	int y = tree[index].l;
	tree[index].l = tree[y].r;
	tree[index].countl = tree[y].countr;
	tree[y].r = index;
	tree[y].countr = tree[index].countl + tree[index].countr + 1;
	index = y;
}

void insert(int &index, int nkey) {
	if(index == -1) {
		index = ++size;
		tree[index].l = tree[index].r = -1;
		tree[index].rand_fix = rand();
		tree[index].key = nkey;
		tree[index].countl = tree[index].countr = 0;
		return ;
	}
	if(nkey < tree[index].key) {
		tree[index].countl++;
		insert(tree[index].l, nkey);
		if(tree[tree[index].l].rand_fix > tree[index].rand_fix)
			r_rotate(index);
	} else {
		tree[index].countr++;
		insert(tree[index].r, nkey);
		if(tree[tree[index].r].rand_fix > tree[index].rand_fix)
			l_rotate(index);
	}
}

bool remove(int &index, int nkey) {
	if(index == -1)
		return false;
	if(nkey < tree[index].key)
		return remove(tree[index].l, nkey);
	else if(nkey > tree[index].key)
		return remove(tree[index].r, nkey);
	if(tree[index].l == -1 && tree[index].r == -1)
		index = -1;
	else if(tree[index].l == -1)
		index = tree[index].r;
	else if(tree[index].r == -1)
		index = tree[index].l;
	else {
		if(tree[tree[index].l].rand_fix < tree[tree[index].r].rand_fix) {
			l_rotate(index);
			remove(tree[index].l, nkey);
		} else {
			r_rotate(index);
			remove(tree[index].r, nkey);
		}
	}
	return true;
}

int getKth(int index, int count) {
	if(index == -1)
		return -1;
	if(tree[index].countl + 1 == count)
		return tree[index].key;
	if(tree[index].l == -1)
		return getKth(tree[index].r, count-1);
	if(tree[index].countl + 1 < count)
		return getKth(tree[index].r, count - (tree[index].countl+1));
	return getKth(tree[index].l, count);
}

void init() {
	size = root = -1;
}

void print(int index) {
	printf("%d ", tree[index].key);
	if(tree[index].l != -1)
		printf("left: %d ",tree[tree[index].l].key);
	if(tree[index].r != -1)
		printf("right:%d ",tree[tree[index].r].key);
	printf("count: %d  %d\n", tree[index].countl, tree[index].countr);
	if(tree[index].l != -1)
		print(tree[index].l);
	if(tree[index].r != -1)
		print(tree[index].r);
}

int main() {
	freopen("in.txt", "r", stdin);
	int n, m, i;
	int x, now, cur;
	init();
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	now = cur = 0;
	for(i = 0; i < m; i++) {
		scanf("%d", &x);
		while(now < x) {
			insert(root, a[now++]);
		}
		printf("%d\n", getKth(root, ++cur));
	}
	/* print(root); */
	return 0;
}
