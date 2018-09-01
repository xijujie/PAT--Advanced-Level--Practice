#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 20;
struct node {
	int key, height = 1;
	node *left = nullptr, *right = nullptr;
};
int getHeight(node *root) {
	if (root == nullptr) return 0;
	return root->height;
}
void updateHeight(node *root) {
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}
node *rightRotate(node *root) { //ll
	node *tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	updateHeight(root);
	updateHeight(tmp);
	return tmp;
}
node *leftRotate(node *root) { //rr
	node *tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	updateHeight(root);
	updateHeight(tmp);
	return tmp;
}
node *insert(node *root, int t) {
	if (root == nullptr) {
		root = new node;
		root->key = t;
		return root;
	}
	if (t < root->key) { 
		root->left = insert(root->left, t);
		if (getHeight(root->left) - getHeight(root->right) == 2) {
			if (t < root->left->key) root = rightRotate(root);
			else {
				root->left = leftRotate(root->left);
				root = rightRotate(root);
			}
		}
	}
	else {
		root->right = insert(root->right, t);
		if (getHeight(root->left) - getHeight(root->right) == -2) {
			if (t > root->right->key) root = leftRotate(root);
			else {
				root->right = rightRotate(root->right);
				root = leftRotate(root);
			}
		}
	}
	updateHeight(root);
	return root;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, t;
	node *root = nullptr;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t); 
		root = insert(root, t);
	}
	printf("%d\n", root->key);
	return 0;
}