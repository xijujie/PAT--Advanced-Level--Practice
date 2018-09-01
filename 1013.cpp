#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1001;
int g[maxn][maxn] = { 0 }, vis[maxn], n;
void dfs(int u, int t) {
	vis[u] = 1;
	for (int v = 1; v <= n; ++v) {
		if (g[u][v] && !vis[v])
			dfs(v, t);
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	int m, k, u, v, t, cnt;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &u, &v);
		g[u][v] = 1; 
		g[v][u] = 1;
	}
	for (int i = 0; i < k; ++i) {
		scanf("%d", &t);
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		vis[t] = 1;
		for (int u = 1; u <= n; ++u) {
			if (!vis[u]) {
				dfs(u, t);
				cnt++;
			}
		}
		printf("%d\n", cnt - 1);
	}
	return 0;
}