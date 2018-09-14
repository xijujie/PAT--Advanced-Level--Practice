#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 21;
struct Node {
	string s;
	int l, r;
} node[maxn];
int isroot[maxn];
string inorder(int root) {
	if (node[root].l == -1 && node[root].r == -1) return node[root].s;
	string ans = "(";
	if (node[root].l != -1) ans += inorder(node[root].l);
	ans += node[root].s;
	if (node[root].r != -1) ans += inorder(node[root].r);
	return ans + ")";
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, root;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> node[i].s >> node[i].l >> node[i].r;
		if (node[i].l != -1) isroot[node[i].l] = 1;
		if (node[i].r != -1) isroot[node[i].r] = 1;
	}
	for (root = 1; root <= n && isroot[root]; ++root);
	string ans = inorder(root);
	if (ans[0] == '(') ans = ans.substr(1, ans.size() - 2);//去掉最外部多余括号
	cout << ans << endl;  
	return 0;
}