#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;
const int maxn = 500, inf = 0x3fffffff;
int g[maxn][maxn], gt[maxn][maxn], d[maxn], t[maxn], vis[maxn], pre[maxn], inter[maxn];
vector<int> ansd, anst;
int main() {
	//freopen("in.txt","r",stdin);
	int n, m, u, v, f, t1, t2, sou, des;
	fill(g[0], g[0] + maxn * maxn, inf);
	fill(gt[0], gt[0] + maxn * maxn, inf);
	scanf("%d%d", &n, &m);
	for (int i = 0; i<m; ++i) {
		scanf("%d%d%d%d%d", &u, &v, &f, &t1, &t2);
		if (f == 1) {
			g[u][v] = t1;
			gt[u][v] = t2;
		}
		else {
			g[u][v] = g[v][u] = t1;
			gt[u][v] = gt[v][u] = t2;
		}
	}
	scanf("%d%d", &sou, &des);
	fill(d, d + n, inf);
	fill(t, t + n, inf);
	d[sou] = 0;
	t[sou] = 0;
	for (int i = 0; i < n; ++i) {
		int minu = inf, u = -1;
		for (int j = 0; j<n; ++j) {
			if (!vis[j] && d[j]<minu) {
				minu = d[j];
				u = j;
			}
		}
		if (u == -1) break;
		vis[u] = 1;
		for (int v = 0; v<n; ++v) {
			if (vis[v] || g[u][v] == inf) continue;
			if (d[u] + g[u][v] < d[v] ||(d[u] + g[u][v] == d[v] && t[u] + gt[u][v] < t[v])) {
				d[v] = d[u] + g[u][v];
				t[v] = t[u] + gt[u][v];
				pre[v] = u;
			}
		}
	}
	for (u = des; u != sou; u = pre[u]) ansd.push_back(u);
	fill(t, t + n, inf);
	fill(vis, vis + n, 0);
	t[sou] = 0;
	for (int i = 0; i < n; ++i) {
		int minu = inf, u = -1;
		for (int j = 0; j<n; ++j) {
			if (!vis[j] && t[j]<minu) {
				minu = t[j];
				u = j;
			}
		}
		if (u == -1) break;
		vis[u] = 1;
		for (int v = 0; v<n; ++v) {
			if (vis[v] || gt[u][v] == inf) continue;
			if (t[u] + gt[u][v] < t[v] || (t[u] + gt[u][v] == t[v] && inter[u] + 1 < inter[v])) {
				t[v] = t[u] + gt[u][v];
				inter[v] = inter[u] + 1;
				pre[v] = u;
			}
		}
	}
	for (u = des; u != sou; u = pre[u]) anst.push_back(u);
	if (ansd == anst) {
		printf("Distance = %d; Time = %d: %d", d[des], t[des], sou);
		for (int i = ansd.size() - 1; i >= 0; --i) printf(" -> %d", ansd[i]);
	}
	else {
		printf("Distance = %d: %d", d[des], sou);
		for (int i = ansd.size() - 1; i >= 0; --i) printf(" -> %d", ansd[i]);
		printf("\n");
		printf("Time = %d: %d", t[des], sou);
		for (int i = anst.size() - 1; i >= 0; --i) printf(" -> %d", anst[i]);
	}
	printf("\n");
	return 0;
}