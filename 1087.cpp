#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<climits>
using namespace std;
const int maxn = 200, inf = INT_MAX;
int g[maxn][maxn], happy[maxn], d[maxn], h[maxn], num[maxn], citynum[maxn], pre[maxn];
bool vis[maxn];
map<string, int> mp;
string str[maxn];
void print(int u) {
	if (u == 0) {
		cout << str[0];
		return;
	}
	print(pre[u]);
	cout << "->" << str[u];
}
int main() {
	//freopen("in.txt", "r", stdin);
	string s, s1, s2;
	int n, k, t, des, u, v;
	cin >> n >> k >> s;
	mp[s] = 0;
	str[0] = s;
	for (int i = 1; i < n; ++i) {
		cin >> s >> t;
		if (s == "ROM") des = i;
		mp[s] = i;
		str[i] = s;
		happy[i] = t;
	}
	fill(g[0], g[0] + maxn * maxn, inf);
	for (int i = 0; i < k; ++i) {
		cin >> s1 >> s2 >> t;
		u = mp[s1]; v = mp[s2];
		g[u][v] = g[v][u] = t;
	}
	fill(d, d + maxn, inf);
	fill(citynum, citynum + maxn, inf);
	d[0] = 0;
	citynum[0] = 0;
	num[0] = 1;
	for (int i = 0; i < n; ++i) {
		int minu = inf, u = -1;
		for (int j = 0; j < n; ++j) {
			if (!vis[j] && d[j] < minu) {
				minu = d[j];
				u = j;
			}
		}
		if (u == -1) break;
		vis[u] = true;
		for (int v = 0; v < n; ++v) {
			if (vis[v] || g[u][v] == inf) continue;
			if (d[u] + g[u][v] < d[v]) {
				d[v] = d[u] + g[u][v];
				h[v] = h[u] + happy[v];
				citynum[v] = citynum[u] + 1;
				num[v] = num[u];
				pre[v] = u;
			}
			else if (d[u] + g[u][v] == d[v]) {
				num[v] += num[u];
				if (h[u] + happy[v] > h[v] || (h[u] + happy[v] == h[v] && citynum[u] + 1 < citynum[v])) {
					h[v] = h[u] + happy[v];
					citynum[v] = citynum[u] + 1;
					pre[v] = u;
				}
			}
		}
	}
	cout << num[des] << " " << d[des] << " " << h[des] << " " << h[des] / citynum[des] << endl;
	print(des);
	return 0;
}