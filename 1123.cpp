#include <iostream> 
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 10;
struct node {
	int k;
	node *l, *r;
};
int getheight(node *root) {
	if (root == nullptr) return 0;
	return max(getheight(root->l), getheight(root->r)) + 1;
}
void leftrot(node *&root) {
	node *tmp = root->r;
	root->r = tmp->l;
	tmp->l = root;
	root = tmp;
}
void rightrot(node *&root) {
	node *tmp = root->l;
	root->l = tmp->r;
	tmp->r = root;
	root = tmp;
}
void insert(node *&root, int k) {
	if (root == nullptr) {
		root = new node;
		root->k = k;
		root->l = root->r = nullptr;
		return;
	}
	if (k < root->k) {
		insert(root->l, k);
		if (getheight(root->l) - getheight(root->r) == 2) {
			if (k < root->l->k) rightrot(root);
			else {
				leftrot(root->l);
				rightrot(root);
			}
		}
	}
	else {
		insert(root->r, k);
		if (getheight(root->r) - getheight(root->l) == 2) {
			if (k > root->r->k) leftrot(root);
			else {
				rightrot(root->r);
				leftrot(root);
			}
		}
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	node *root = nullptr;
	queue<node *> q;
	int n, k, cnt = 0, flag = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &k);
		insert(root, k);
	}
	q.push(root);
	while (!q.empty()) {
		root = q.front();
		q.pop();
		if (root == nullptr) flag = 0;
		else {
			cnt++;
			if (cnt == n) {
				printf("%d\n", root->k);
				break;
			}
			printf("%d ", root->k);
			q.push(root->l);
			q.push(root->r);
		}
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}