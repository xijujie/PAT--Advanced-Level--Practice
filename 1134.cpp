#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 10000;
int ver[maxn];
struct Edge {
	int u, v;
} e[maxn];
int main() {
	//freopen("in.txt","r",stdin);
	int n, m, u, v, k, num, t, flag;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &u, &v);
		e[i].u = u;
		e[i].v = v;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		flag = 1;
		memset(ver, 0, sizeof(ver));
		scanf("%d", &num);
		for (int j = 0; j < num; ++j) {
			scanf("%d", &t);
			ver[t] = 1;
		}
		for (int j = 0; j < m; ++j) {
			if (ver[e[j].u] == 0 && ver[e[j].v] == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}