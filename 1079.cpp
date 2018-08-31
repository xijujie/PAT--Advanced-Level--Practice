#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100000;
double p, r, total = 0;
struct Node {
	vector<int> child;
	double amount;
} node[maxn];
void dfs(int root, double price) {
	int l = node[root].child.size();
	if (l == 0) {
		total += price * node[root].amount;
		return;
	}
	for (int i = 0; i < l; ++i) dfs(node[root].child[i], price*(1 + r / 100));
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, t;
	scanf("%d%lf%lf", &n, &p, &r);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &m);
		if (m == 0) scanf("%lf", &node[i].amount);
		else {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &t);
				node[i].child.push_back(t);
			}
		}
		
	}	
	dfs(0, p);
	printf("%.1f\n", total);
	return 0;
}