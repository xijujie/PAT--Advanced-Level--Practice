#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#include<cstring>
using namespace std;
const int maxn = 1011, inf = INT_MAX; 
int vis[maxn], dis[maxn];
struct Node {
	int v, d;
	Node(int _v, int _d) :v(_v), d(_d) {};
};
vector<Node> adj[maxn];
struct cmp {
	bool operator()(int a, int b) {
		return dis[a] > dis[b];
	}
};
priority_queue<int, vector<int>, cmp> q;
int change(char *s, int n) {
	int i = 0, len = strlen(s), res = 0;
	if (s[0] == 'G') i++;
	for (; i < len; ++i) {
		res = res * 10 + s[i] - '0';
	}
	return s[0] == 'G' ? res + n : res;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, k, ds, u, v, t;
	char s1[5], s2[5]; //注意最长为4位(1000)
	scanf("%d%d%d%d", &n, &m, &k, &ds);
	for (int i = 0; i < k; ++i) {
		scanf("%s%s%d", s1, s2, &t);
		u = change(s1, n);
		v = change(s2, n);
		adj[u].push_back(Node(v, t));
		adj[v].push_back(Node(u, t));
	}
	int ansdis = -1, ansavg = inf, ans = -1;
	for (int s = n + 1; s <= n + m; ++s) {
		fill(vis, vis + maxn, 0);
		fill(dis, dis + maxn, inf);
		dis[s] = 0;
		q.push(s);
		while (!q.empty()) {
			u = q.top();	
			q.pop();
			if (vis[u] == 1) continue;
			vis[u] = 1;
			for (int j = 0; j < adj[u].size(); ++j) {
				v = adj[u][j].v;
				if (!vis[v] && dis[u] + adj[u][j].d < dis[v]) {
					dis[v] = dis[u] + adj[u][j].d;
					q.push(v);
				}
			}
		}
		int minimum = inf, avg = 0;	
		for (int i = 1; i <= n; ++i) {
			avg += dis[i];
			if (dis[i] < minimum)  minimum = dis[i];
			if (dis[i] > ds) {
				minimum = -2;
				break;
			}
		}
		if (minimum > ansdis || (minimum == ansdis && avg < ansavg)) {
			ansdis = minimum;
			ansavg = avg;
			ans = s;
		}
	}
	if(ans == -1) printf("No Solution\n");
	else printf("G%d\n%.1f %.1f\n", ans - n, 1.0 * ansdis, 1.0 * ansavg / n);
	return 0;
}