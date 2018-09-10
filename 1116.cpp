#include <iostream> 
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 10000;
int r[maxn], check[maxn];
bool isprime(int n) {
	for (int i = 2; i <= (int)sqrt(n); ++i) {
		if (n % i == 0) return false;
	}
	return true;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, k, id;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &id);
		r[id] = i;
	}
	scanf("%d", &k);
	for (int i = 1; i <= k; ++i) {
		scanf("%d", &id);
		printf("%04d: ", id);
		if (r[id] == 0) printf("Are you kidding?\n");
		else {
			if (check[id]) printf("Checked\n");
			else {
				check[id] = 1;
				if (r[id] == 1) printf("Mystery Award\n");
				else if (isprime(r[id])) printf("Minion\n");
				else printf("Chocolate\n");
			}
		}
	}
	return 0;
}