#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> ans, tmp;
int n, k, p, asum = 0;
int fac[21]; 

void dfs(int nowk, int kpsum, int ksum, int i) {	
	if (nowk == k) {
		if (kpsum == n && ksum > asum) {
			ans = tmp;
			asum = ksum;
		}
		return;
	}
	if (kpsum + fac[i] <= n) {
		tmp.push_back(i);
		dfs(nowk + 1, kpsum + fac[i], ksum + i, i);
		tmp.pop_back();
	}
	if (i - 1 > 0) dfs(nowk, kpsum, ksum, i - 1);
}

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d%d", &n, &k, &p);
	int i, t;
	for (i = 1; (t = (int)pow(i, p)) <= n; ++i) fac[i] = t;
	dfs(0, 0, 0, i - 1);
	if (asum == 0) printf("Impossible");
	else {
		printf("%d = %d^%d", n, ans[0], p);
		for (int i = 1; i < ans.size(); ++i) {
			printf(" + %d^%d", ans[i], p);
		}
	}
	return 0;
}
