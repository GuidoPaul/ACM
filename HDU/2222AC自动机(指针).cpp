/*************************************************************************
  > File Name: hdu2222other.cpp
  > Author: Bslin
  > Mail: Baoshenglin1994@gmail.com
  > Created Time: 2014年07月18日 星期五 20时23分12秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
using namespace std;

const int kind = 26;
const int maxn = 500010;  // 子串数 * 子串长度

struct node {
	node *fail;       // 失败指针
	node *next[kind]; // Tire每个节点的26个子节点（最多26个字母）
	int end;          // 是否为该单词的最后一个节点, 1为是
	/* int id; */
	node() {          // 构造函数初始化
		fail = NULL;
		end = 0;
		/* id = 0; */
		memset(next, 0, sizeof(next));  /////////////////////////
	}
}*q[maxn];            // 队列，方便用于bfs构造失败指针
char keyword[51];     // 输入的单词
char str[1000001];    // 模式串

void insert(char *str, node *root) { //构建Tire树
	node *p = root;
	int i = 0, index;
	while(str[i]) {
		index = str[i]-'a';
		if(p->next[index] == NULL) {
			p->next[index] = new node();
		}
		p = p->next[index];
		i++;
	}
	p->end++;   // 最后一个字母
}

void build_ac_auto(node *root) { //构建fail指针
	int head, tail; //队列的头尾指针
	int i;
	head = tail = 0;
	root->fail = NULL;
	q[head++] = root;
	while(head != tail) {
		node *temp=q[tail++];
		node *p = NULL;
		for(i = 0; i < kind;i++) {
			if(temp->next[i] != NULL) {
				if(temp==root) {
					temp->next[i]->fail=root;
				} else {
					p = temp->fail;
					while(p != NULL) {
						if(p->next[i] != NULL) {
							temp->next[i]->fail = p->next[i];
							break;
						}
						p = p->fail;
					}
					if(p == NULL) {
						temp->next[i]->fail=root;
					}
				}
				q[head++] = temp->next[i];
			}
		}
	}
}

int query(node *root) {
	int i = 0, cnt = 0, index;
	int len = strlen(str);
	node *p = root;
	while(str[i]) {
		index = str[i] - 'a';
		while(p->next[index] == NULL && p != root) {
			p = p->fail;
		}
		p = p->next[index];
		p = (p == NULL) ? root : p;
		node *temp = p;
		while(temp != root && temp->end > 0) {
			cnt += temp->end;
			temp->end = -1;
			temp = temp->fail;
		}
		i++;
	}
	return cnt;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, t;
	scanf("%d", &t);
	while(t--) {
		node *root = new node();
		scanf("%d", &n);
		while(n--) {
			scanf("%s", keyword);
			insert(keyword, root);
		}
		build_ac_auto(root);
		scanf("%s", str);
		printf("%d\n", query(root));
	}
	return 0;
}

