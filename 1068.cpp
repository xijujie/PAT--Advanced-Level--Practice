#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 10001, maxv = 101;
int val[maxn], dp[maxv], choice[maxn][maxv];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, flag = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
	sort(val + 1, val + n + 1, greater<int>());
	for (int i = 1; i <= n; ++i) {
		for (int v = m; v >= val[i]; --v){
			if (dp[v] <= dp[v - val[i]] + val[i]) {
				dp[v] = dp[v - val[i]] + val[i];
				choice[i][v] = 1;
			}
			
		}
	}
	if (dp[m] < m) printf("No Solution");
	else {
		for (int i = n; i >= 1; --i) {
			if (m == 0) break;
			while (choice[i][m] == 0) --i;
			if (flag) printf(" ");
			else flag = 1;
			printf("%d", val[i]);
			m -= val[i];
		}
	}
	return 0;
}