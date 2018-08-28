#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100000, maxm = 20;
int p[maxn] = { 0 }, num[maxm];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, d;
	p[1] = 1;//注意1不是质数
	for (int i = 2; i < maxn; ++i) {
		if (p[i] == 0) {
			for (int j = i + i; j < maxn; j += i) p[j] = 1;
		}
	}
	while (1) {
		scanf("%d", &n);
		if (n < 0) break;
		scanf("%d", &d);
		if (p[n]) printf("No\n"); 
		else {
			int m = 0;
			while (n) {
				num[m++] = n % d;
				n /= d;
			}
			for (int i = 0; i < m; ++i) n = n * d + num[i]; 
			if (p[n]) printf("No\n");
			else printf("Yes\n");
		}	
	}
	return 0;
}
