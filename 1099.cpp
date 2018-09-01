#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 100;
struct Node {
	int key, l, r;
} node[maxn];
int in[maxn], num = 0;
void inorder(int root) {
	if (root == -1) return;
	inorder(node[root].l);
	node[root].key = in[num++];
	inorder(node[root].r);
}
void levelorder(int root) {
	queue<int> q;
	int flag = 0;
	q.push(root);
	while (!q.empty()) {
		root = q.front();
		q.pop();
		if (flag) printf(" ");
		else flag = 1;
		printf("%d", node[root].key);
		if (node[root].l != -1) q.push(node[root].l);
		if (node[root].r != -1) q.push(node[root].r);
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d%d", &node[i].l, &node[i].r);
	for (int i = 0; i < n; ++i) scanf("%d", &in[i]);
	sort(in, in + n);
	inorder(0);
	levelorder(0);
	return 0;
}
