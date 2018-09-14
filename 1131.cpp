#include <iostream> 
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
const int maxn = 10000, inf = INT_MAX;
int d[maxn], tran[maxn], vis[maxn], pre[maxn], line[maxn];
struct cmp {
	bool operator() (const int &a, const int &b) {
		return d[a] > d[b];
	}
};
struct node {
	int v, line;
	node(int _v, int _l) :v(_v), line(_l) {}
};
vector<node> adj[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, k, u, v, s, e, t, l;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &m, &u);
		for (int j = 1; j < m; ++j) {
			scanf("%d", &v);
			adj[u].push_back(node(v, i));
			adj[v].push_back(node(u, i));
			u = v;
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d%d", &s, &e);
		priority_queue<int, vector<int>, cmp> q;
		fill(d, d + maxn, inf);
		fill(tran, tran + maxn, inf);
		memset(vis, 0, sizeof(vis));
		d[s] = tran[s] =  0;
		q.push(s);
		while (!q.empty()) {
			u = q.top();
			q.pop();
			if (u == e) break;
			if (vis[u]) continue;
			vis[u] = 1;
			for (int j = 0; j < adj[u].size(); ++j) {
				if (vis[adj[u][j].v]) continue;
				v = adj[u][j].v;
				if (adj[u][j].line != line[u]) t = tran[u] + 1;
				else t = tran[u];
				if (d[v] == inf || (d[v] == d[u] + 1 && t < tran[v])) {
					d[v] = d[u] + 1;
					tran[v] = t;
					pre[v] = u;
					line[v] = adj[u][j].line;
				}
				q.push(v);
			}	
		}
		vector<int> vec;		
		while (u != s) {
			vec.push_back(u);
			u = pre[u];
		}
		l = line[vec[vec.size() - 1]];
		printf("%d\n", d[e]);
		for (int j = vec.size() - 1; j >= 0;--j ) {
			if (j == 0 || line[vec[j - 1]] != l) {
				printf("Take Line#%d from %04d to %04d.\n", l, u, vec[j]);
				u = vec[j];
				if (j > 0) l = line[vec[j - 1]];
			}
		}
	}
	return 0;
}