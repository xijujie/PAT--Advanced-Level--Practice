#include<iostream>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	int m, n, l, t, ans, cnt, i;
    scanf("%d%d%d", &m, &n, &ans);
	l = m * n, i = 1, cnt = 1;
	while (i < l) {
		scanf("%d", &t);
		i++;
		if (t == ans) cnt++;
		else cnt--;
		if (cnt == 0) {
			scanf("%d", &ans);
			cnt = 1;
			i++;
		}
	}
	printf("%d", ans);
	return 0;
}

//也可以借助一个数组进行计数
//const int maxn = 17000000;
//int a[maxn] = { 0 };
//int main() {
//	//freopen("in.txt", "r", stdin);
//	int m, n, l, t;
//	scanf("%d%d", &m, &n);
//	for (int i = 0, l = m * n; i < l; ++i) {
//		scanf("%d", &t);
//		a[t]++;
//		if (a[t] > l / 2) {
//			printf("%d", t);
//			break;
//		}
//	}
//	return 0;
//}