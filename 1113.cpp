#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000;
int a[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, s1 = 0, s = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		s += a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n / 2; ++i) s1 += a[i];
	printf("%d %d\n", n % 2, s - s1 - s1);
	return 0;
}
