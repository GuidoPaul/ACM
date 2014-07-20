/*************************************************************************
  > File Name: hdu2222.cpp
  > Author: Bslin
  > Mail: Baoshenglin1994@gmail.com
  > Created Time: 2014年07月18日 星期五 16时29分26秒
 ************************************************************************/

#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

const int kind = 26;
const int maxn = 500010;

struct node {
	int child[kind];
	int fail;
	/* int id; */
	int end;
	void init() {
		memset(child, 0, sizeof(child));
		fail = -1;
		/* id = 0; */
		end = 0;
	}
} T[maxn];

int root, tot;
char keyword[60], str[1000010];

void init() {
	root = tot = 0;
	T[root].init();
}

/* void insert(char *s,int id){ */
void insert(char buf[]) {
	int p, idx, len, i;
	len = strlen(buf);
	p = root;
	for (i = 0; i < len; ++i) {
		idx = buf[i] - 'a';  //
		if(!T[p].child[idx]) {
			T[++tot].init();
			T[p].child[idx] = tot;
		}
		p = T[p].child[idx];
	}
	/* T[p].id = id; */
	T[p].end ++;
}

void build_ac_auto() {
	int qu[maxn], tmp, son;
	int head, tail, p, i;
	head = tail = 0;
	qu[tail ++] = root;
	while(head < tail) {
		tmp = qu[head++];
		for(i = 0; i < kind; i ++) {
			if(T[tmp].child[i]) {
				son = T[tmp].child[i];
				if(tmp == root) {
					T[son].fail = root;
				} else {
					p = T[tmp].fail;
					T[son].fail = T[p].child[i];
				}
				qu[tail++] = son;
			} else { // trie图, 设定虚拟节点
				p = T[tmp].fail;
				if(tmp == root) T[tmp].child[i] = root;
				else T[tmp].child[i] = T[p].child[i];
			}
		}
	}
}

int query(char str[]) {
	int p, idx, len, tmp, i;
	int res = 0;
	len = strlen(str);
	p = root;
	for (i = 0; i < len; ++i) {
		idx = str[i] - 'a';  //
		p = T[p].child[idx];
		tmp = p;
		while(tmp != root) {
			res += T[tmp].end;
			T[tmp].end = 0;
			tmp = T[tmp].fail;
		}
	}
	return res;
}


int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, n, i;
	scanf("%d", &cas);
	while(cas --) {
		init();
		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			scanf("%s", keyword);
			insert(keyword);
		}
		build_ac_auto();
		scanf("%s", str);
		printf("%d\n", query(str));
	}
	return 0;
}
