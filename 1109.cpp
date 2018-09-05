#include <iostream>
#include <cstring>
#include <algorithm> 
using namespace std;
struct Per {
	char s[9];
	int h;
} p[10000];
int ans[10001];
bool cmp(Per a, Per b) {
	if (a.h != b.h) return  a.h > b.h;
	else return strcmp(a.s, b.s) < 0;
}
int main() {
	int n, k, l, mid, t = 0;
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%s %d", p[i].s, &p[i].h);
	sort(p, p + n, cmp);
	for (int row = 0; row < k; ++row) {
		l = row == 0 ? n / k + n % k : n / k;
		mid = (l / 2) + 1;
		ans[mid] = t++;
		for (int i = mid - 1, j = mid + 1; i >= 1; --i, ++j) {
			ans[i] = t++;
			if (j <= l) ans[j] = t++;
		}
		for (int i = 1; i <= l; ++i) {
			if (i != 1) printf(" ");
			printf("%s", p[ans[i]].s);
		}
		printf("\n");
	}
	return 0;
}
