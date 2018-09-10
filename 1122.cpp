#include <iostream> 
#include <vector>
#include <set>
using namespace std;
const int maxn = 201;
int g[maxn][maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, u, v, k, num, flag;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &u, &v);
		g[u][v] = g[v][u] = 1;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", &num);
		vector<int> v(num);
		set<int> s;
		flag = 1;
		for (int j = 0; j < num; ++j) {
			scanf("%d", &v[j]);
			s.insert(v[j]);
		}
		for (int j = 0; j < num - 1; ++j) {
			if (g[v[j]][v[j + 1]] == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 0 || v[0] != v[num - 1] || s.size() != n || num != n + 1) printf("NO\n"); 
		else printf("YES\n");
	}
	return 0;
}