#include <iostream> 
#include <vector>
using namespace std;
const int maxn = 1001;
vector<int> adj[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, u, v, k, cnt = 0;
	scanf("%d%d", &n, &m);
	vector<int> indegree(n + 1);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		indegree[v]++;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		vector<int> tmp(indegree);
		int flag = 1;
		for (int j = 0; j < n; ++j) {
			scanf("%d", &u);
			if (tmp[u] != 0) flag = 0;
			else {
				for (int v = 0; v < adj[u].size(); ++v) tmp[adj[u][v]]--;
			}
		}
		if (flag == 0) {
			if (cnt) printf(" ");
			else cnt = 1;
			printf("%d", i);
		}
	}
	return 0;
}