#include<iostream>
#include<cctype>
#include<queue>
using namespace std;
const int maxn = 10;
struct Node {
	int left = -1, right = -1, flag = 0;
} node[maxn];
int f = 0;
void print(int root) {
	if (f) printf(" %d", root);
	else {
		printf("%d", root);
		f = 1;
	}
}
void levelorder(int root) {
	int flag = 0;
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		root = q.front();
		q.pop();
		print(root);
		if (node[root].right != -1) q.push(node[root].right);
		if (node[root].left != -1) q.push(node[root].left);
	}
}
void inorder(int root) {
	if (root == -1) return;
	inorder(node[root].right);
	print(root);
	inorder(node[root].left);
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, root;
	char l, r;
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%c %c\n", &l, &r);
		if (isdigit(l)) {
			node[i].left = l - '0';
			node[l - '0'].flag = 1;
		}
		if (isdigit(r)) {
			node[i].right = r - '0';
			node[r - '0'].flag = 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (node[i].flag == 0) {
			root = i;
			break;
		}
	}	
	levelorder(root);
	printf("\n");
	f = 0;
	inorder(root);
	return 0;
}