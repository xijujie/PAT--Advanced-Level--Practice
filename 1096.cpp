#include<iostream>
#include<cmath>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	long long n, i, j, m, t, ansi = 0, ansj = 0;
	scanf("%lld", &n);
	m = (long long) sqrt(n);
	for (i = 2; i <= m; ++i) {
		t = 1;
		for (j = i;; ++j) {
			t *= j;
			if (n % t != 0) break;
		}
		if (j - i  > ansj - ansi) {
			ansj = j; ansi = i;
		}
	}
	if (ansi == 0) printf("1\n%lld", n); //根号n范围内可能无解，则结果为n本身；
	else {
		printf("%lld\n%lld", ansj - ansi, ansi);
		for (ansi = ansi + 1; ansi < ansj; ++ansi) printf("*%lld", ansi);
	}
	return 0;
}
