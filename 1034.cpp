#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
const int maxn = 2000;
map<string, int> mp, ans;
struct Node {
	int total = 0;
	string name;
	vector<int> adj;
}node[maxn];
int vis[maxn] = { 0 }, k, num, head;
void dfs(int u) {
	vis[u] = 1;
	num++;
	k += node[u].total;
	if (node[u].total > node[head].total) {
		head = u;
	}
	for (int i = 0; i < node[u].adj.size();++i) {
		if (!vis[node[u].adj[i]]) 
			dfs(node[u].adj[i]);
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	string s1, s2;
	int n, K, t, m = 0, cnt = 0;
	cin >> n >> K;
	for (int i = 0; i < n; ++i) {
		cin >> s1 >> s2 >> t;
		if (mp.find(s1) == mp.end()) {
			mp[s1] = m;
			node[m++].name = s1;
		}
		if (mp.find(s2) == mp.end()) {
			mp[s2] = m;
			node[m++].name = s2;
		}
		node[mp[s1]].adj.push_back(mp[s2]);
		node[mp[s2]].adj.push_back(mp[s1]);
		node[mp[s1]].total += t;
		node[mp[s2]].total += t;
	}
	for (int u = 0; u < m; ++u) {
		if (!vis[u]) {
			k = 0; num = 0; head = u;
			dfs(u);
			if (num > 2 && k > K * 2) {
				ans[node[head].name] = num;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	for (auto it = ans.begin(); it != ans.end(); ++it) 
		cout << it->first << " " << it->second << endl;
	return 0;
}