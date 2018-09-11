#include <iostream> 
#include <algorithm>
using namespace std;
int a[10000];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, t;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n);
	double ans = a[0];
	for (int i = 1; i < n; ++i) ans = (ans + a[i]) / 2;
	printf("%d\n", (int)ans);
	return 0;
}