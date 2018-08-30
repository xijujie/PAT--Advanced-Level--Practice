#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct Node {
	int i, j, k;
};
int ori[6][3] = { { 1,0,0 }, { -1,0,0 }, { 0,1,0 }, { 0,-1,0 }, { 0,0,1 }, { 0,0,-1 } };
int g[60][1286][128], inq[60][1286][128] = { 0 };
int  m, n, l, t, total = 0;
bool judge(int i, int j, int k) { //未越界并且当前位置为1并且没有入队过；
	return (i < l && i >= 0 && j < m && j >= 0 && k < n && k >= 0 && g[i][j][k] && !inq[i][j][k]);
}

int bfs(Node node) {
	queue<Node> q;
	Node tmp;
	int cnt = 0, i, j, k;
	q.push(node);
	inq[node.i][node.j][node.k] = 1;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		cnt++;
		for (int r = 0; r < 6; ++r) {
			i = tmp.i + ori[r][0];
			j = tmp.j + ori[r][1];
			k = tmp.k + ori[r][2];
			if (judge(i, j, k)) { 
				node.i = i; node.j = j; node.k = k;
				q.push(node);
				inq[i][j][k] = 1;
			}
		}	
	}
	if (cnt >= t) return cnt;
	else return 0;
}

int main() {
	//freopen("in.txt", "r", stdin);	
	scanf("%d%d%d%d", &m, &n, &l, &t);
	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < n; ++k)
				scanf("%d", &g[i][j][k]);
		}
	}
	Node node;
	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < n; ++k) {
				if (g[i][j][k] && !inq[i][j][k]) {
					node.i = i; node.j = j; node.k = k;
					total += bfs(node);
				}
			}
		}
	}
	printf("%d", total);
	return 0;
}
