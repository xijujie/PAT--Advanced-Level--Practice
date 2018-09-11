#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 30;
vector<int> v[maxn];
int in[maxn], post[maxn], maxlevel = 0;
void getlevel(int inl, int inr, int pol, int por, int level) {
	if (inl > inr) return;
	int root = post[por], pos = inl;
	maxlevel = max(maxlevel, level);
	v[level].push_back(root);
	while (in[pos] != root) ++pos;
	getlevel(inl, pos - 1, pol, pol + pos - inl - 1, level + 1);
	getlevel(pos + 1, inr, pol + pos - inl, por - 1, level + 1);
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, flag = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &in[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &post[i]);
	getlevel(0, n - 1, 0, n - 1, 0);
	printf("%d", v[0][0]);
	for (int i = 1; i <= maxlevel; ++i) {
		if (i % 2) 
			for (int j = 0; j < v[i].size(); ++j) printf(" %d", v[i][j]);
		else 
			for (int j = v[i].size() - 1; j >= 0; --j) printf(" %d", v[i][j]);
	}
	return 0;
}