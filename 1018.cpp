#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
const int maxn = 501, inf = INT_MAX;
int g[maxn][maxn], weight[maxn], d[maxn], minsend = inf, minback = inf; 
bool vis[maxn];
vector<int> pre[maxn], tmp, ans;
void dfs(int u){
	if (u == 0) {
		int send = 0, remain = 0;
		for (int i = tmp.size() - 1; i >= 0; --i) {
			if (weight[tmp[i]] >= 0) {
				remain += weight[tmp[i]];
			}
			else {
				remain += weight[tmp[i]];
				if (remain < 0) {
					send += abs(remain);
					remain = 0;
				}
			}
		}
		if (send < minsend || (send == minsend && remain < minback)) {
			minsend = send;
			minback = remain;
			ans = tmp;
		}
		return;
	}
	for (int i = 0; i < pre[u].size(); ++i) {
		tmp.push_back(pre[u][i]);
		dfs(pre[u][i]);
		tmp.pop_back();
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	fill(g[0], g[0] + maxn * maxn, inf);
	fill(d, d + maxn, inf);
	int maxcap, n, sp, m, u, v, t, minu;
	scanf("%d%d%d%d", &maxcap, &n, &sp, &m);
	for (int i = 1; i <= n; ++i) { 
		scanf("%d", &weight[i]);
		weight[i] -= maxcap / 2;
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &t);
		g[u][v] = g[v][u] = t;
	}
	d[0] = 0;
	for (int i = 0; i <= n; ++i) {
		minu = inf, u = -1;
		for (int j = 0; j <= n; ++j) {
			if (!vis[j] && d[j] < minu) {
				minu = d[j];
				u = j;
			}
		}
		if (u == -1) break;
		vis[u] = true;
		for (int v = 0; v <= n; ++v) {
			if (!vis[v] && g[u][v] != inf) {
				if (d[u] + g[u][v] < d[v]) {
					d[v] = d[u] + g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
					
				}
				else if (d[u] + g[u][v] == d[v]) {
					pre[v].push_back(u);
					
				}
			}
		}
	}
	tmp.push_back(sp);
	dfs(sp);
	printf("%d 0", minsend);
	for (int i = ans.size() - 2; i >= 0; --i) printf("->%d", ans[i]);
	printf(" %d", minback);
	return 0;
}