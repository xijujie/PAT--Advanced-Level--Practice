#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100000;
int a[maxn + 1], curmax[maxn + 1], ans[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m = 0;
	scanf("%d", &n);
	curmax[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		curmax[i] = max(a[i], curmax[i - 1]);
		
	}
	int curmin = a[n];
	for (int i = n; i >= 1; --i) {
		curmin = min(a[i], curmin);
		if (a[i] <= curmin && a[i] >= curmax[i]) ans[m++] = a[i]; 
	}
	printf("%d\n", m);
	if(m) {
		sort(ans, ans + m);
		printf("%d",ans[0]);
		for (int i = 1; i < m; ++i) printf(" %d", ans[i]);
	}
	printf("\n"); //注意主元个数为0的情况，第二行虽然没有主元输出，但需要输出一个换行.
	return 0;
}

