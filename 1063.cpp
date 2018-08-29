#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;
const int maxn = 51;
unordered_set<int> sets[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, k, t, t1, t2;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &m);
		for (int j = 0; j < m; ++j) {
			scanf("%d", &t);
			sets[i].insert(t);
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d%d", &t1, &t2);
		int cnt = 0;
		for (auto it = sets[t2].begin(); it != sets[t2].end(); ++it) {
			if (sets[t1].find(*it) != sets[t1].end()) cnt++;
		}
		printf("%.1f%%\n", 100.0 * cnt / (sets[t1].size() + sets[t2].size() - cnt));
	}
	return 0;
}


