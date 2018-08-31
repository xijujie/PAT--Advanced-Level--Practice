#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100;
int weight[maxn], s;
vector<int> node[maxn], tmp;
vector<vector<int> > ans;

bool cmp(vector<int> &a, vector<int> &b) {
	int l = min(a.size(), b.size());
	for (int i = 0; i < l; ++i) {
		if (a[i] != b[i]) return a[i] > b[i];
	}
	return a.size() > b.size();
}

void dfs(int root, int nows) {
	if (node[root].size() == 0) {
		if (nows == s) ans.push_back(tmp); 
		return;
	}
	for (int i = 0; i < node[root].size(); ++i) {
		int w = weight[node[root][i]];
		if (nows + w <= s) {
			tmp.push_back(w);
			dfs(node[root][i], nows + w);
			tmp.pop_back();
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, id, k, t;
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &weight[i]);
	}	
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &t);
			node[id].push_back(t);
		}
	}
	dfs(0, weight[0]);
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d", weight[0]);
		for (int j = 0; j < ans[i].size(); ++j) printf(" %d", ans[i][j]);
		printf("\n");
	}
	return 0;
}