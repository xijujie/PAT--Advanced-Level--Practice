#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000;
int c[maxn], p[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, ans = 0;	
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) scanf("%d", &p[i]);
	sort(c, c + n);
	sort(p, p + m);
	for (int i = 0; i < n && i < m && c[i] < 0 && p[i] < 0; ++i) ans += c[i] * p[i];
	for (int i = n - 1, j = m - 1; i >= 0 && j >= 0 && c[i] > 0 && p[j] > 0; --i, --j) ans += c[i] * p[j];
	printf("%d", ans);
	return 0;
}

