#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <climits>
using namespace std;
const int maxn = 201;
int g[maxn][maxn];
int main() {
	//freopen("in.txt","r",stdin);
	int n, m, t, k, u, v, ans = INT_MAX, ansi = -1;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &t);
		g[u][v] = g[v][u] = t;
	}
	scanf("%d", &k);
	for (int i = 1; i <= k; ++i) {
		int sum = 0, num;
		scanf("%d", &num);
		vector<int> v(num);
		set<int> s;
		for (int j = 0; j < num; ++j) {
			scanf("%d", &v[j]);
			s.insert(v[j]);
		}
		for (int j = 0; j < num - 1; ++j) {
			if (g[v[j]][v[j + 1]] == 0) {
				sum = -1; break;
			}
			sum += g[v[j]][v[j + 1]];
		}
		if (v[num - 1] == v[0] && s.size() == n && sum != -1) {
			if(num == n + 1) printf("Path %d: %d (TS simple cycle)\n", i, sum);
			else printf("Path %d: %d (TS cycle)\n", i, sum);
			if (sum < ans) {
				ans = sum;
				ansi = i;
			}
		}
		else if (sum != -1)
			printf("Path %d: %d (Not a TS cycle)\n", i, sum);
		else printf("Path %d: NA (Not a TS cycle)\n", i);
	}
	printf("Shortest Dist(%d) = %d\n", ansi, ans);
	return 0;
}