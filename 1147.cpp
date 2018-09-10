#include <iostream> 
#include <algorithm>
using namespace std;
const int maxn = 1001;
int a[maxn], n, m;
void postorder(int i) {
	if (i * 2 <= n) postorder(i * 2);
	if (i * 2 + 1 <= n) postorder(i * 2 + 1);
	if (i == 1) printf("%d\n", a[i]);
	else printf("%d ", a[i]);
}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; ++i) {
		int flag = 1;
		for (int j = 1; j <= n; ++j) scanf("%d", &a[j]);
		if (a[1] > a[2]) {
			for (int j = 1; j * 2 <= n; ++j) {
				if (a[j * 2] > a[j] || (j * 2 + 1 <= n && a[j * 2 + 1] > a[j])) {
					flag = 0; break;
				}
			}
			if (flag == 1) printf("Max Heap\n");
		}
		else {
			for (int j = 1; j * 2 <= n; ++j) {
				if (a[j * 2] < a[j] || (j * 2 + 1 <= n && a[j * 2 + 1] < a[j])) {
					flag = 0; break;
				}
			}
			if (flag == 1) printf("Min Heap\n");
		}
		if (flag == 0) printf("Not Heap\n");
		postorder(1);
	}
	return 0;
}