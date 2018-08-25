#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000;
int seq[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, p, maxlen = 0;
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; ++i) scanf("%d", &seq[i]);
	sort(seq, seq + n);
	for (int i = 0, j = 0; j < n;) { //two pointers
		while (j < n && seq[j] <= (long long)seq[i] * p) ++j;
		if (j - i > maxlen) maxlen = j - i;
		++i;
	}
	//for (int i = 0; i < n; ++i) { //¶þ·Ö²éÕÒ
	//	int j = upper_bound(seq + i + 1, seq + n, (long long)seq[i] * p) - seq;
	//	maxlen = max(maxlen, j - i);
	//}
	printf("%d", maxlen);
	return 0;
}

