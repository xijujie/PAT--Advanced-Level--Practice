#include<iostream>
#include<climits>
using namespace std;
const int maxn = 200000;
int a[maxn + 1];
int main() {
	//freopen("in.txt", "r", stdin);
	int m, n, i, j, count, t, ans;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", &a[i]);
	a[n] = INT_MAX; //可以在序列尾添加INF作为边界
	scanf("%d", &m);
	scanf("%d", &t);
	for (i = 0, j = 0, count = 0; count <= (n + m - 1) / 2; ++count) {
		if (j == m || a[i] < t) ans = a[i++];
		else {
			ans = t;
			scanf("%d", &t);
			j++;
		}
	}
	printf("%d", ans);
	return 0;
}
