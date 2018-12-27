#include <iostream>
#include <string>
#include <set>
using namespace std;
const int maxn = 10000;
struct Edge {
	int u, v;
} edge[maxn];
int color[maxn];
int main() {
	int n, m, num;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &edge[i].u, &edge[i].v);
	}
	scanf("%d", &num);
	for (int i = 0; i < num; ++i) {
		set<int> s;
		bool flag = true;
		for (int j = 0; j < n; ++j) {
			scanf("%d", &color[j]);
			s.insert(color[j]);
		}
		for (int j = 0; j < m; ++j) {
			if (color[edge[j].u] == color[edge[j].v]) {
				flag = false;
				break;
			}
		}
		if(flag) printf("%d-coloring\n", s.size());
		else printf("No\n");
	}
	return 0;
}
