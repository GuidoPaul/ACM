/*************************************************************************
	> File Name: E.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月02日 星期六 12时11分06秒
 ************************************************************************/

#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;
#define N 10010

vector<int> G1[N], G2[N];
vector<int> S;
int head[N], tot, vis[N], sccno[N], contain[N], out[N], scc_cnt;

void dfs1(int u) {
	int i;
	if(vis[u]) return ;
	vis[u] = 1;
	for(i = 0; i < G1[u].size(); i ++) dfs1(G1[u][i]);
	S.push_back(u);
}

void dfs2(int u) {
	int i;
	if(sccno[u]) return ;
	sccno[u] = scc_cnt;
	contain[scc_cnt] ++;
	for(i = 0; i < G2[u].size(); i ++) dfs2(G2[u][i]);
}

void find_scc(int n) {
	int i;
	scc_cnt = 0;
	S.clear();
	memset(sccno, 0, sizeof(sccno));
	memset(vis, 0, sizeof(vis));
	for(i = 0; i < n; i ++) dfs1(i);
	for(i = n-1; i >= 0; i --) {
		if(!sccno[S[i]]) {
			scc_cnt ++;
			dfs2(S[i]);
		}
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int n, m, i;
	int u, v;
	int flag, ans;
	while(scanf("%d%d", &n, &m) != EOF) {
		memset(out, 0, sizeof(out));
		memset(contain, 0, sizeof(contain));
		for (i = 0; i < n; ++i) {
			G1[i].clear();
			G2[i].clear();
		}
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &u, &v);
			u --;
			v --;
			G1[u].push_back(v);
			G2[v].push_back(u);
		}
		find_scc(n);
		for (u = 0; u < n; ++u) {
			for (i = 0; i < G1[u].size(); ++i) {
				v = G1[u][i];
				if(sccno[u] != sccno[v]) {
					out[sccno[u]] ++;
				}
			}
		}
		flag = 0;
		for (i = 1; i <= scc_cnt; ++i) {
			if(out[i] == 0) {
				flag ++;
				ans = contain[i];
			}
			if(flag == 2) break;
		}
		if(flag == 2) printf("0\n");
		else printf("%d\n", ans);
	}
	return 0;
}
