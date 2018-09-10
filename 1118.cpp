#include <iostream> 
#include <algorithm>
using namespace std;
const int maxn = 10001;
int father[maxn], a[maxn];
int Find(int u) {
	if (father[u] == 0) return u;
	return father[u] = Find(father[u]);
}
void Union(int u, int v) {
	int ru = Find(u), rv = Find(v);
	if (ru != rv) father[rv] = ru;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, k, q, u, v, num = 0, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &a[j]);
			num = max(num, a[j]);
		}
		for (int j = 1; j < k; ++j) {
			Union(a[0], a[j]);
		}
	}
	for (int i = 1; i <= num; ++i) {
		if (father[i] == 0) cnt++;
	}
	printf("%d %d\n", cnt, num);
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d%d", &u, &v);
		int ru = Find(u), rv = Find(v);
		if (ru != rv) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}