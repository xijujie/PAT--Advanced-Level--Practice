#include<iostream>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
const int maxn = 10001;
vector<int> adj[maxn];
set<int> ans, tmp;
int vis[maxn] = { 0 }, maxdepth = 0;
void dfs(int u, int depth) {
	vis[u] = 1;
	if (depth > maxdepth) {
		maxdepth = depth;
		tmp.clear();
		tmp.insert(u);
	}
	else if (depth == maxdepth) {
		tmp.insert(u);
	}
	for (int i = 0; i < adj[u].size(); ++i) {
		if (!vis[adj[u][i]]) dfs(adj[u][i], depth + 1);
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, u, v, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (u = 1; u <= n; ++u) {
		if (!vis[u]) {
			dfs(u, 0);
			cnt++;
		}
	}
	if (cnt > 1) printf("Error: %d components\n", cnt);
	else {
		ans = tmp;
		memset(vis, 0, sizeof(vis));
		dfs(*ans.begin(), 0);
		for (auto it = tmp.begin(); it != tmp.end(); ++it)
			ans.insert(*it);
		for (auto it = ans.begin(); it != ans.end(); ++it)
		    printf("%d\n", *it);
	}
	return 0;
}