#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	int num, n, m;
	scanf("%d", &num);
	vector<int> v(num);
	for (int i = 0; i < num; ++i) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end(), greater<int>());
	for (n = (int)sqrt(num); n >= 1 && num % n; --n);
	m = num / n;
	vector<vector<int> > ans(m, vector<int>(n));
	int si = 0, sj = 0, ei = m - 1, ej = n - 1, k = 0, i, j;
	while (ei >= si && ej >= sj) {
		for (i = si, j = sj; j <= ej && k < num; ++j) ans[i][j] = v[k++];
		for (i = si + 1, j = ej; i <= ei && k < num; ++i) ans[i][j] = v[k++];
		for (i = ei, j = ej - 1; j >= sj && k < num; --j) ans[i][j] = v[k++];
		for (i = ei - 1, j = sj; i > si && k < num; --i) ans[i][j] = v[k++];
		si++; sj++; ei--; ej--;
	}
	for (i = 0; i < m; ++i) {
		for (j = 0; j < n; ++j) {
			if (j != 0) printf(" ");
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}