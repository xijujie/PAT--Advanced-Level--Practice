#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 500, inf = 501;
int g[maxn][maxn], dis[maxn], cost[maxn][maxn], c[maxn], vis[maxn], pre[maxn];
void print(int u, int s) {
	if (u != s) print(pre[u], s);
	printf("%d ", u);
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, s, d, u, v, t1, t2, minu;
	scanf("%d%d%d%d", &n, &m, &s, &d);
	fill(g[0], g[0] + maxn * maxn, inf);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d%d", &u, &v, &t1, &t2);
		g[u][v] = g[v][u] = t1;
		cost[u][v] = cost[v][u] = t2;
	}
	fill(dis, dis + maxn, inf);
	fill(c, c + maxn, inf);
	for (int i = 0; i < n; ++i) pre[i] = i;
	dis[s] = 0;
	c[s] = 0;
	for (int i = 0; i < n; ++i) {
		minu = inf, u = -1;
		for (int j = 0; j < n; ++j) {
			if (!vis[j] && dis[j] < minu) {
				minu = dis[j];
				u = j;
			}
		}
		if (u == -1) break;
		vis[u] = 1;
		for (int v = 0; v < n; ++v) {
			if (g[u][v] != inf && !vis[v]) {
				if (dis[u] + g[u][v] < dis[v]) {
					dis[v] = dis[u] + g[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}
				else if (dis[u] + g[u][v] == dis[v] && c[u] + cost[u][v] < c[v]) {
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}
			}
			
		}
		
	}
	print(d, s);
	printf("%d %d\n", dis[d], c[d]);
	return 0;
}