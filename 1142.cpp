#include <iostream> 
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 201;
int g[maxn][maxn], a[maxn], mp[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, ne, m, k, u, v;
	scanf("%d%d", &n, &ne);
	for (int i = 0; i < ne; ++i) {
		scanf("%d%d", &u, &v);
		g[u][v] = g[v][u] = 1;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		memset(mp, 0, sizeof(mp));
		int flag = 1;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &a[j]);
			mp[a[j]] = 1;
		}
		for (int u = 0; u < k - 1 && flag; ++u) {
			for (int v = u + 1; v < k; ++v) {
				if (g[a[u]][a[v]] == 0) {
					printf("Not a Clique\n");
					flag = 0; break;
				}
			}
		}
		if (flag == 0) continue;
		for (int u = 1; u <= n; ++u) {
			if (mp[u] == 0) {
				int j = 0;
				for (; j < k && g[u][a[j]] == 1; ++j); 
				if (j == k) {
					printf("Not Maximal\n");
					flag = 0; break;
				}
			}
		}
		if(flag) printf("Yes\n");
	}
	return 0;
}