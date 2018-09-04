#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int center(int lc, int rc, int n) {
	int r = 0;
	for (; lc - r >= 0 && rc + r <= n && s[lc - r] == s[rc + r]; ++r);
	return (r - 1) * 2 + rc - lc + 1;
}
int main() {
	//freopen("in.txt", "r", stdin);
	getline(cin, s);
	int n = s.size() - 1, t, ans = 1;
	for (int i = 0; i <= n - 1; ++i) {
		t = max(center(i, i, n), center(i, i + 1, n));
		ans = max(ans, t);
	}
	printf("%d", ans);
	return 0;
}


//¶¯Ì¬¹æ»®
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//int dp[1001][1001];
//int main() {
//	//freopen("in.txt", "r", stdin);
//	string s;
//	getline(cin, s);
//	int n = s.size(), ans = 1;
//	for (int j = 0; j < n; ++j) {
//		for (int i = 0; i <= j; ++i) {
//			if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1] == 1)) {
//				dp[i][j] = 1;
//				ans = max(ans, j - i + 1);
//			
//		}
//	}
//	printf("%d", ans);
//	return 0;
//}