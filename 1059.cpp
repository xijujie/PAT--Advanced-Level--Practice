#include<iostream>
#include<cmath>
using namespace std;
struct Factor {
	int p, k;
} fac[10];
bool isprime(int n) {
	int m = (int)sqrt(n);
	for (int i = 2; i <= m; ++i) {
		if (n%i == 0) return false;
	}
	return true;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	printf("%d=", n);
	if (n == 1) {
		printf("1");return 0;
	}
	int m = (int)sqrt(n), j = 0;
	for (int i = 2; i <= m; ++i) {
		if (n%i == 0 && isprime(i)) {
			fac[j].p = i;
			fac[j].k = 0;
			while (n%i == 0) {
				fac[j].k++; n /= i;
			}
			j++;
		}
	}	
	if (n != 1) {
		fac[j].p = n;
		fac[j++].k = 1;
	}
	for (int i = 0; i < j; ++i) {
		if(i != 0) printf("*");
		printf("%d",fac[i].p);
		if (fac[i].k != 1) printf("^%d", fac[i].k);
	}
	return 0;
}
