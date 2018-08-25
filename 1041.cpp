#include<iostream>
using namespace std;
const int maxn = 100001;
int a[maxn] = { 0 }, bet[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &bet[i]);
		++a[bet[i]];
	}

	for (i = 0; i < n && a[bet[i]] != 1; ++i);
	if (i == n) printf("None");
	else printf("%d", bet[i]);
	return 0;
}