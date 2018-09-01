#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 1001;
vector<int> adj[maxn];
int level[maxn], inq[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, l, m, u, k, cnt;
	scanf("%d%d", &n, &l);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &m);
		for (int j = 0; j < m; ++j) {
			scanf("%d", &u);
			adj[u].push_back(i);
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", &u);
		memset(inq, 0, sizeof(inq));
		memset(level, 0, sizeof(level));
		queue<int> q;
		cnt = 0;
		q.push(u);
		inq[u] = 1;
		level[u] = 0;
		while (!q.empty()) {
			u = q.front();
			q.pop();
			if (level[u] < l) {
				for (int i = 0; i < adj[u].size(); ++i) {
					if (!inq[adj[u][i]]) {
						level[adj[u][i]] = level[u] + 1;
						q.push(adj[u][i]);
						inq[adj[u][i]] = 1;
						cnt++;
					}
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}