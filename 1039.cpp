#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 26 * 26 * 26 * 10 ;
vector<vector<int> > vec(maxn);
int change(char *s) {
	int i, res = 0;
	for (i = 0; i < 3; ++i) {
		res = res * 26 + s[i] - 'A';
	}
	res = res * 10 + s[i] - '0';
	return res;
}
int main() {
   // freopen("in.txt", "r", stdin);
	char s[5];
	int n, k, t, m;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d%d", &t, &m);
		for (int j = 0; j < m; ++j) {
			scanf("%s", s);
			vec[change(s)].push_back(t);
		}
	}
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		t = change(s);
		sort(vec[t].begin(), vec[t].end());
		int l = vec[t].size();
		printf("%s %d", s, l);
		for (int j = 0; j < l; ++j) printf(" %d", vec[t][j]);
		printf("\n");
		
	}
	return 0;
}
