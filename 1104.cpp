#include<iostream>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	double t, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &t);
		ans += t * (i + 1)*(n - i);
	}
	printf("%.2f", ans);
	return 0;
}