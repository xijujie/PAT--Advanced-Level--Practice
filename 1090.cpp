#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int maxn = 100000;
int maxdepth = -1, cnt = 0;
vector<int> node[maxn];
void dfs(int root, int depth) {
	int l = node[root].size();
	if (l == 0) {
		if (depth > maxdepth) {
			maxdepth = depth;
			cnt = 1;
		}
		else if (depth == maxdepth) cnt++;
		return;
	}
	for (int i = 0; i < l; ++i) dfs(node[root][i], depth + 1);
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, t, root;
	double p, r;
	scanf("%d%lf%lf", &n, &p, &r);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		if (t == -1) root = i;
		else {
			node[t].push_back(i);
		}

	}
	dfs(root, 0);
	printf("%.2f %d\n", pow((1 + r / 100), maxdepth) * p, cnt);
	return 0;
}