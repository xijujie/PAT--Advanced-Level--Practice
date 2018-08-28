#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 10000, maxt = 20000;
int a[maxn], h[maxt] = { 0 };
bool isprime(int n) {
	if (n == 1) return false;
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n%i == 0) return false;
	}
	return true;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int m, n, tsize, pos;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (tsize = m; tsize < maxt; ++tsize) {
		if (isprime(tsize)) break;
	}
	for (int i = 0; i < n; ++i) {
		if (i != 0) printf(" ");
		int j = 0;
		pos = a[i] % tsize;
		for (; j < tsize && h[(pos + j * j) % tsize]; ++j);
		if (j == tsize) printf("-");
		else {
			pos = (pos + j * j) % tsize;
			h[pos] = 1;
			printf("%d", pos);
		}
	}
	return 0;
}
