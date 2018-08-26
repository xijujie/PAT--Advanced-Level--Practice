//1.two pointers 27ms
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100000;
int a[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n);

	for (i = 0, j = n - 1; i < j;) {
		if (a[i] + a[j] == m) break;
		else if (a[i] + a[j] < m) ++i;
		else --j;
	}
	if (i == j) printf("No Solution");
	else printf("%d %d", a[i], a[j]);
	return 0;
}

//2.散列法 21ms
//#include<iostream>
//#include<cstring>
//using namespace std;
//int a[100000] = { 0 }, mp[501] = { 0 };
//int main() {
//	//freopen("in.txt", "r", stdin);
//	int n, m, i;
//	scanf("%d%d", &n, &m);
//	for (i = 0; i < n; ++i) {
//		scanf("%d", &a[i]);
//		mp[a[i]]++;
//	}	
//	for (i = 1; i < 501; ++i) {
//		//m-i可能会大于500
//		if ((i != m - i && m - i < 501 && mp[i] && mp[m - i]) || (i == m - i && mp[i] > 1))
//			break;
//	}
//	if (i == 501) printf("No Solution");
//	else printf("%d %d", i, m - i);
//	return 0;
//}

//3.二分查找 34ms
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int maxn = 100000;
//int a[maxn];
//int main() {
//	//freopen("in.txt", "r", stdin);
//	int n, m, i, j;
//	scanf("%d%d", &n, &m);
//	for (i = 0; i < n; ++i) scanf("%d", &a[i]);
//	sort(a, a + n);
//	for (i = 0; i < n; ++i) {
//		j = lower_bound(a + i + 1, a + n, m - a[i]) - a;
//		if(j < n && a[j]== m - a[i]) break;
//	}
//	if (i == n) printf("No Solution");
//	else printf("%d %d", a[i], a[j]);
//	return 0;
//}