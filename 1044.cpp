#include<iostream>
#include<algorithm>
const int maxn = 100001;
using namespace std;
int a[maxn]; //a[i] = D0+D1+D2+...Di ,D0=0;
int search(int m, int n) {
	int t = -1;
	for (int i = 0; i < n; ++i) {
		int j = lower_bound(a + i + 1, a + n + 1, m + a[i]) - a;
		if (j != n + 1) {
			if (a[j] - a[i] == m) printf("%d-%d\n", i + 1, j);
			if (t == -1 || a[j] - a[i] - m < t) t = a[j] - a[i] - m; 
		}
	}
	return t;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, t;
	scanf("%d%d", &n, &m);
	a[0] = 0;
	for (int i = 1; i <= n; ++i) { 
		scanf("%d", &t);
		a[i] = a[i - 1] + t;
	}	
	t = search(m, n);
	if (t != 0) search(m + t, n);
	return 0;
}