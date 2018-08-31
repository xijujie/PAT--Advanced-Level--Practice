#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 100;
struct Node {
	vector<int> child;
	int level;
} node[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, index, num, t;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &index, &num);
		for (int j = 0; j < num; ++j) {
			scanf("%d", &t);
			node[index].child.push_back(t);
		}
	}
	int front, nowlevel = 1, cnt = 0, maxcnt = 0, maxlevel;
	queue<int> q;
	node[1].level = 1;
	q.push(1);
	while (!q.empty()) {
		front = q.front();
		q.pop();
		if (node[front].level > nowlevel) {
			if (cnt > maxcnt) {
				maxcnt = cnt; maxlevel = nowlevel;
			}
			nowlevel++;
			cnt = 1;
		}
		else cnt++;
		for (int i = 0; i < node[front].child.size(); ++i) {
			node[node[front].child[i]].level = node[front].level + 1;
			q.push(node[front].child[i]);
		}
	}
	if (cnt > maxcnt) {
		maxcnt = cnt; maxlevel = nowlevel;
	}
	printf("%d %d\n", maxcnt, maxlevel);
	return 0;
}