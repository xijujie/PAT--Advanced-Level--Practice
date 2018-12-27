#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1001;
int a[maxn], n;
vector<int> tmp;
void dfs(int i) {
	tmp.push_back(a[i]);
	if (i * 2 > n) {
		for (int j = 0; j < tmp.size(); ++j)
			printf("%d%c", tmp[j], j == tmp.size() - 1 ? '\n' : ' ');
	}
	else {
		if (i * 2 + 1 <= n) dfs(i * 2 + 1);
		if (i * 2 <= n) dfs(i * 2);
	}
	tmp.pop_back();
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);
	dfs(1);
	bool ismin = true, ismax = true;
	for (int i = 2; i <= n; ++i) {
		if (a[i / 2] > a[i]) ismin = false;
		if (a[i / 2] < a[i]) ismax = false;
	}
	if(ismax) printf("Max Heap\n");
	else if(ismin) printf("Min Heap\n");
	else printf("Not Heap\n");
	return 0;
}
