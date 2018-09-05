#include <iostream>
#include <string>
#include <algorithm> 
#include <queue>
using namespace std;
struct Node {
	int l, r;
} node[20];
int isroot[20];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, t, root, last = -1, cnt = 0;
	string l, r;
	queue<int> q;
	scanf("%d\n", &n);
	for (int i = 0; i<n; ++i) {
		cin >> l >> r;
		if (l == "-") node[i].l = -1;
		else {
			t = stoi(l);
			node[i].l = t;
			isroot[t] = 1;
		}
		if (r == "-") node[i].r = -1;
		else {
			t = stoi(r);
			node[i].r = t;
			isroot[t] = 1;
		}
	}
	for (int i = 0; i<n; ++i) {
		if (isroot[i] == 0) {
			root = i; break;
		}
	}
	q.push(root);
	while (!q.empty()) {
		t = q.front();
		q.pop();
		cnt++;
		if (t == -1)  break;
		if (cnt == n) {
			last = t;  break;
		}
		q.push(node[t].l);
		q.push(node[t].r);
	}
	if (last != -1) printf("YES %d\n", last);
	else printf("NO %d\n", root);
	return 0;
}