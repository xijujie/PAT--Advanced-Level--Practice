#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1001;
int a[maxn], hobby[maxn] = { 0 };
int findroot(int i) {
	if (a[i] < 0) return i;
	return a[i] = findroot(a[i]);
}
void Union(int i, int j) {
	int ri = findroot(i), rj = findroot(j);
	if (ri != rj) {
		a[rj] += a[ri];
		a[ri] = rj;
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, k, h, cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) a[i] = -1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d:", &k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &h);
			if (hobby[h] == 0) hobby[h] = i;
			else Union(i, hobby[h]);
		}
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n && a[i] < 0; ++i) cnt++;
	printf("%d\n%d", cnt, -a[1]);
	for (int i = 2; i <= n && a[i] < 0; ++i) printf(" %d", -a[i]);
	return 0;
}