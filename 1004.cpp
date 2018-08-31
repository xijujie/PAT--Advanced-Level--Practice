#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100;
int leafnum[maxn] = { 0 };
vector<int> node[maxn];
void dfs(int root, int depth) {
	if (node[root].size() == 0) {
		leafnum[depth]++;
		return;
	}
	for (int i = 0; i < node[root].size(); ++i) 
		dfs(node[root][i], depth + 1);
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, id, num, t;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &id, &num);
		for (int j = 0; j < num; ++j) {
			scanf("%d", &t);
			node[id].push_back(t);
		}
	}
	dfs(1, 0);
	int i = n - 1;
	for (; i >= 0 && leafnum[i] == 0; --i);
	printf("%d", leafnum[0]);
	for (int j = 1; j <= i; ++j) printf(" %d", leafnum[j]);
	return 0;
}