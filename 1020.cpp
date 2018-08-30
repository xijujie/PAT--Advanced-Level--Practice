#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 30;
int post[maxn], in[maxn];
struct Node {
	int data, level, num;
} node[maxn];
int num = 0;
void levelorder(int pl, int pr, int inl, int inr, int level) {
	if (pl > pr) return;
	int root = post[pr], pos;
	node[num].num = num;
	node[num].data = root;
	node[num++].level = level;
	for (pos = inl; in[pos] != root; ++pos);
	levelorder(pl, pl + pos - inl - 1, inl, pos - 1, level + 1);
	levelorder(pl + pos - inl, pr - 1, pos + 1, inr, level + 1);
}
bool cmp(Node a, Node b) {
	return a.level != b.level ? a.level < b.level : a.num < b.num;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &post[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &in[i]);
	levelorder(0, n - 1, 0, n - 1, 1);
	sort(node, node + num, cmp);
	printf("%d", node[0].data);
	for (int i = 1; i < num; ++i) printf(" %d", node[i].data);
	return 0;
}