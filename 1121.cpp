#include <iostream> 
#include <cstring>
#include <set>
using namespace std;
const int maxn = 100000;
int couple[maxn], party[maxn], mp[maxn];
set<int> ans;
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, a, b;
	memset(couple, -1, sizeof(couple));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a, &b);
		couple[a] = b;
		couple[b] = a;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &party[i]);
		if (couple[party[i]] != -1) mp[couple[party[i]]] = 1;
	}
	for (int i = 0; i < m; ++i) {
		if (mp[party[i]] == 0) ans.insert(party[i]);
	}
	printf("%d\n", ans.size());
	for (auto it = ans.begin(); it != ans.end(); ++it) {
		if (it != ans.begin()) printf(" ");
		printf("%05d", *it);
	}
	return 0;
}
