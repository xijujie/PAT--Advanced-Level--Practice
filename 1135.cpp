#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	int key, num;
	node *l, *r;
};
void creat(int key, node *&root) {
	if (root == nullptr) {
		root = new node;
		root->key = key;
		root->num = -1;
		root->l = root->r = nullptr;
		return;
	}
	if (abs(key) <= abs(root->key)) creat(key, root->l);
	else creat(key, root->r);
}
int getblack(node *root) {
	if (root == nullptr) return 0;
	if (root->num == -1) {
		int l = max(getblack(root->l), getblack(root->r));
		root->num = root->key  > 0 ? l + 1 : l;
	}
	return root->num;
}
bool judge(node *root) {
	if (root == nullptr) return true;
	if (root->key < 0) {
		if (root->l && root->l->key < 0) return false;
		if (root->r && root->r->key < 0) return false;
	}
	if(getblack(root->l) != getblack(root->r)) return false;
	return judge(root->l) && judge(root->r);
}
int main() {
	//freopen("in.txt","r",stdin);
	int k, n, flag, key;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		node *root = nullptr;
		flag = 1;
		scanf("%d", &n);
		for (int j = 0; j < n; ++j) {
			scanf("%d", &key);
			creat(key, root); //BST前序遍历序列即插入序列
		}
		if (root->key < 0) flag = 0;
		else flag = judge(root);
		if (flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}