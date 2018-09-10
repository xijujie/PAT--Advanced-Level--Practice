#include <iostream> 
#include <algorithm>
using namespace std;
const int maxn = 1000;
int level[maxn];
struct node {
	int k;
	node *l, *r;
};
void insert(node *&root, int k) {
	if (root == nullptr) {
		root = new node;
		root->k = k;
		root->l = root->r = nullptr;
		return;
	}
	if (k <= root->k) insert(root->l, k);
	else insert(root->r, k);
}
void dfs(node *root, int lev) {
	level[lev]++;
	if (root->l) dfs(root->l, lev + 1);
	if (root->r) dfs(root->r, lev + 1);
}
int main() {
	//freopen("in.txt", "r", stdin);
	node *root = nullptr;
	int n, k;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &k);
		insert(root, k);
	}
	dfs(root, 0);
	int i = maxn - 1;
	for (; i >= 1 && level[i] == 0; --i);
	printf("%d + %d = %d\n", level[i], level[i - 1], level[i] + level[i - 1]);
	return 0;
}