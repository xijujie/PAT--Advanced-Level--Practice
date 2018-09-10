#include <iostream> 
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 20000;
int h[maxn];
bool isprime(int n) {
	for (int i = 2; i <= (int)sqrt(n); ++i) 
		if (n%i == 0) return false;
	return true;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int t, n, m, k, tmp, total = 0;
	scanf("%d%d%d", &t, &n, &m);
	for (; isprime(t) == false; ++t);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &k);
		int j = 0, pos = k % t;
		for (; j < t && h[(pos + j * j) % t] != 0; ++j);
		if (j == t) printf("%d cannot be inserted.\n", k);
		else h[(pos + j * j) % t] = k;
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &k);
		int j = 0, pos = k % t;
		for (; j < t; ++j) {
			tmp = h[(pos + j * j) % t];
			if (tmp == k || tmp == 0)  break;
		}
		total += j + 1;
	}
	printf("%.1f\n", 1.0*total/m);
	return 0;
}