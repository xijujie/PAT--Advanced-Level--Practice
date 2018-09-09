#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 101;
int a[maxn];
int main() {
	//freopen("in.txt","r",stdin);
	int n, k, i, j, flag = 0;
	scanf("%d", &n);
	for (int k = 1; k <= n; ++k) scanf("%d", &a[k]);
	for (i = 1; i <= n - 1; ++i) {
		for (j = i + 1; j <= n; ++j) {
			int lw = 0, lh = 0;
			for (k = 1; k <= n; ++k) {
				if (a[k] == i || a[k] == j) {
					if (k != i && k != j) lh++;
					else lw++;
				}
				else if (a[k] < 0 && abs(a[k]) != i && abs(a[k]) != j) {
					if (k != i && k != j) lh++;
					else lw++;
				}
			}	
			if (lh == 1 && lw == 1) {
				flag = 1;break;
			}
		}
		if (flag) break;
	}
	if (flag) printf("%d %d\n", i, j);
	else printf("No Solution\n");
	return 0;
}