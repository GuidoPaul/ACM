/*************************************************************************
  > File Name: poj1056.c
  > Author: Bslin
  > Mail: Baoshenglin1994@gmail.com
  > Created Time: 2014年07月24日 星期四 11时00分15秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

const int kind = 2;
const int maxn = 100;

struct node {
	node *next[kind];
	int end;
	node() {
		end = 0;
		memset(next, 0, sizeof(next));
	}
};

void insert(char *str, node *root) {
	int i, idx, len;
	len = strlen(str);
	node *p = root;
	for (i = 0; i < len; ++i) {
		idx = str[i] - '0';
		if(!p->next[idx]) {
			p->next[idx] = new node();
		}
		p = p->next[idx];
	}
	p->end++;
}

int query(char *str, node *root) {
	int i, len, idx;
	len = strlen(str);
	node *p = root;
	for(i = 0; i < len; i ++) {
		idx = str[i] - '0';
		p = p->next[idx];
	}
	if(p->end > 1) return 1;
	return 0;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, flag, i, cnt;
	char str[1010][20];
	cas = 1;
	cnt = 0;
	node *root = new node();
	while(scanf("%s", str[cnt]) != EOF) {
		if(str[cnt][0] == '9') {
			flag = 0;
			for (i = 0; i < cnt; ++i) {
				if(flag == 1) continue;
				flag = query(str[i], root);
			}
			if(flag == 0) {
				printf("Set %d is immediately decodable\n", cas);
			} else {
				printf("Set %d is not immediately decodable\n", cas);
			}
			cnt = 0;
			cas ++;
		} else {
			insert(str[cnt], root);
			cnt ++;
		}
	}
	return 0;
}
