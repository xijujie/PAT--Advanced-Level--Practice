#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 40000, maxk = 2501;
vector<int> v[maxk];
char s[maxn][5];
bool cmp(int a, int b) {
	return strcmp(s[a], s[b]) < 0;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, k, c, t;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%s%d", s[i], &c);
		for (int j = 0; j < c; ++j) {
			scanf("%d", &t);
			v[t].push_back(i);
		}
	}
	for (int i = 1; i <= k; ++i) {
		int l = v[i].size();
		printf("%d %d\n", i, l);
		sort(v[i].begin(), v[i].end(), cmp);
		for (int j = 0; j < l; ++j) printf("%s\n",s[v[i][j]]);
	}
	return 0;
}