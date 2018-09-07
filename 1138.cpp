#include <iostream>
using namespace std;
const int maxn = 50000;
int pre[maxn], in[maxn];
int search(int pl, int pr, int inl, int inr) {
	int root = pre[pl], pos = inl;
	if (pl == pr) return root;
	for (; in[pos] != root; ++pos);
	if (pos > inl) return search(pl + 1, pl + pos - inl, inl, pos - 1);
	else return search(pl + pos - inl + 1, pr, pos + 1, inr);
}
int main() {
	//freopen("in.txt","r",stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &pre[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &in[i]);
	printf("%d\n", search(0, n - 1, 0, n - 1));
	return 0;
}