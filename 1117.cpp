#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100000;
int a[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n, greater<int>());
	for (i = 0; i < n && i + 1 < a[i] - 1; ++i);
	printf("%d\n", a[i] - 1);
	return 0;
}

