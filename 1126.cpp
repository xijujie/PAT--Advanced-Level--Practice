#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 501;
vector<int> adj[maxn];
int vis[maxn], cnt = 0;
void dfs(int u) {
	vis[u] = 1;
	cnt++;
	for (int v = 0; v < adj[u].size(); ++v) {
		if (vis[adj[u][v]] == 0) dfs(adj[u][v]);
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, u, v, odd = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i) {
		printf("%d", adj[i].size());
		if (i != n) printf(" ");
		else printf("\n");
		if (adj[i].size() % 2) odd++;
	}
	if (cnt == n && odd == 0) printf("Eulerian\n");
	else if (cnt == n && odd == 2) printf("Semi-Eulerian\n");
	else printf("Non-Eulerian\n");
	return 0;
}