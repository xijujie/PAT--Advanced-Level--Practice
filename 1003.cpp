#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
const int maxn = 500;
int g[maxn][maxn], team[maxn], num[maxn], dis[maxn], maxteam[maxn];
bool vis[maxn] = { false };
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, sc, ec, u, v, l;
	scanf("%d%d%d%d", &n, &m, &sc, &ec);
	for (int i = 0; i < n; ++i) scanf("%d", &team[i]);
	fill(g[0], g[0] + maxn * maxn, INT_MAX);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &l);
		g[u][v] = g[v][u] = l;
	}
	fill(dis, dis + maxn, INT_MAX);
	dis[sc] = 0;
	num[sc] = 1;
	maxteam[sc] = team[sc];
	for (int i = 0; i < n; ++i) {
		int mindis = INT_MAX, u = -1;
		for (int j = 0; j < n; ++j) {
			if (vis[j] == false && dis[j] < mindis) {
				mindis = dis[j];
				u = j;
			}
		}
		if (u == -1) break;
		vis[u] = true;
		for (int v = 0; v < n; ++v) {
			if (g[u][v] != INT_MAX && vis[v] == false) {
				if (dis[u] + g[u][v] < dis[v]) {
					dis[v] = dis[u] + g[u][v];
					num[v] = num[u];
					maxteam[v] = maxteam[u] + team[v];
				}
				else if (dis[u] + g[u][v] == dis[v]) {
					num[v] += num[u];
					maxteam[v] = max(maxteam[v], maxteam[u] + team[v]);
				}
			}
		}
	}
	printf("%d %d", num[ec], maxteam[ec]);
	return 0;
}