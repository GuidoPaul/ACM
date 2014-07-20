/*************************************************************************
	> File Name: H.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月17日 星期四 13时41分35秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define M 100010
#define MOD 1000000007

vector<int> G1[M], G2[M];
vector<int> S;
int vis[M], sccno[M], contain[M], out[M], scc_cnt;
int a[M], mmin[M], cnt[M];

void dfs1(int u) {  // 第一次 dfs
	int i;
	if(vis[u]) return ;
	vis[u] = 1;
	for(i = 0; i < G1[u].size(); i ++) dfs1(G1[u][i]);
	S.push_back(u);
}

void dfs2(int u) {  // 第二次 dfs
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
	long long ans1, ans2;
	while(scanf("%d", &n) != EOF) {
		memset(out, 0, sizeof(out));
		memset(contain, 0, sizeof(contain));
		for (i = 0; i < n; i ++) {
			G1[i].clear();
			G2[i].clear();
		}
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		scanf("%d", &m);
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &u, &v);
			u--;
			v--;
			G1[u].push_back(v);
			G2[v].push_back(u);
		}
		find_scc(n);
		/* printf("%d\n", scc_cnt); */
		memset(mmin, 0x4F, sizeof(mmin));
		memset(cnt, 0, sizeof(cnt));
		/* printf("%d\n", mmin[0]); */
		for (u = 0; u < n; ++u) {
			if(mmin[sccno[u]] == a[u]) {
				cnt[sccno[u]] ++;
			} else if(mmin[sccno[u]] > a[u]) {
				mmin[sccno[u]] = a[u];
				cnt[sccno[u]] = 1;
			}
		}
		ans1 = 0;
		ans2 = 1;
		for (i = 1; i <= scc_cnt; ++i) {
			ans1 += mmin[i];
			ans2 = (ans2 * cnt[i]) % MOD;
		}
		printf("%lld %lld\n", ans1, ans2);
	}
	return 0;
}
