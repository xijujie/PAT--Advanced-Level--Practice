#include <cstdio>
#include <cstdlib>
int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	long long a, b, c, s;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld %lld %lld", &a, &b, &c);
		s = a + b;
		if (a > 0 && b > 0 && s < 0) printf("Case #%d: true", i);
		else if (a < 0 && b < 0 && s >= 0) printf("Case #%d: false", i);
		else if (s > c)  printf("Case #%d: true", i);
		else printf("Case #%d: false", i);
		printf("\n");
	}
	return 0;
}