#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000;
int a[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, t, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		a[t] = i;  //t现在位于位置i上
	}
	for (int i = 0; i < n; ++i) {
		if (a[0] == 0 && a[i] != i) {
			swap(a[0], a[i]);
			ans++;
		}
		while (a[0] != 0) {
			swap(a[0], a[a[0]]);
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}

