#include <iostream> 
using namespace std;
const int maxn = 1000;
int a[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int k, n;
	scanf("%d", &k);
	while(k--) {
		int flag = 1;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 0; i < n - 1; ++i) {
			for (int j = i + 1; j < n; ++j){
				if (a[i] == a[j] || abs(a[j] - a[i]) == j - i) {
					flag = 0; break;
				}
			}
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}