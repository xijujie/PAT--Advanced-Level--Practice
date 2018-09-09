#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 100000;
vector<int> adj[maxn];
int mp[maxn], a[maxn];
int main() {
	//freopen("in.txt","r",stdin);
	int n, m, u, v, num, t;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < m; ++i) {
		int flag = 1;
		memset(mp, 0, sizeof(mp));
		scanf("%d", &num);
		for (int j = 0; j < num; ++j) {
			scanf("%d", &a[j]);
			mp[a[j]] = 1;
		}
		for (int j = 0; j < num; ++j) {
			u = a[j];
			for (v = 0; v < adj[u].size(); ++v) {
				if (mp[adj[u][v]] == 1) {
					flag = 0; break;
				}
			}
		}
		if (flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}