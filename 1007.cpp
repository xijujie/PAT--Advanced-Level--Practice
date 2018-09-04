#include<iostream>
int a[10000];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, f, l, tmpf = 0, t = 0, s = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		t += a[i];
		if (t > s) {
			s = t;
			f = tmpf;
			l = i;
		}
		else if (t < 0) {
			t = 0;
			tmpf = i + 1;
		}
	}
	if (s == -1) printf("0 %d %d", a[0], a[n - 1]);
	else printf("%d %d %d", s, a[f], a[l]);
	return 0;
}


//¶¯Ì¬¹æ»®
//#include<iostream>
//const int maxn = 10000;
//int a[maxn], dp[maxn];
//int main() {
//	//freopen("in.txt", "r", stdin);
//	int n, s, f = 0, l = 0, tmpf = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
//	dp[0] = a[0];
//	s = a[0];
//	for (int i = 1; i < n; ++i) {
//		if (a[i] > dp[i - 1] + a[i]) {
//			dp[i] = a[i];
//			tmpf = i;
//		}
//		else dp[i] = dp[i - 1] + a[i];
//		if (dp[i] > s) {
//			s = dp[i];
//			f = tmpf;
//			l = i;
//		}
//	}
//	if (s < 0) printf("0 %d %d", a[0], a[n - 1]);
//	else printf("%d %d %d", s, a[f], a[l]);
//	return 0;
//}

