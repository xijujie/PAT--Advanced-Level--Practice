//最长不下降子序列LIS
#include<iostream>
#include<algorithm>
using namespace std;
int a[10000], dp[10000], mp[201];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, l, t, num = 0, ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) { 
		scanf("%d", &t); 
		mp[t] = i;
	}
	scanf("%d", &l);
	for (int i = 0; i < l; ++i) {
		scanf("%d", &t);
		if (mp[t] != 0) a[num++] = mp[t];
	}
	for (int i = 0; i < num; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (a[i] >= a[j]) dp[i] = max(dp[j] + 1, dp[i]);
		}
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}


//最长公共子序列LCS
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int a[10001], eva[201], dp[201][10001];
//int main() {
//	//freopen("in.txt", "r", stdin);
//	int n, m, l;
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= m; ++i) scanf("%d", &eva[i]);
//	scanf("%d", &l);
//	for (int i = 1; i <= l; ++i) scanf("%d", &a[i]);
//	for (int i = 1; i <= m; ++i) {
//		for (int j = 1; j <= l; ++j) {
//			if (a[j] == eva[i]) dp[i][j] = dp[i][j - 1] + 1;
//			else {
//				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//			}
//		}
//	}
//	printf("%d\n", dp[m][l]);
//	return 0;
//}