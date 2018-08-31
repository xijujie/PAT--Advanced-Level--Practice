#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn = 100000;
vector<int> node[maxn];
int level[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, t;
	double p, r;
	scanf("%d%lf%lf", &n, &p, &r);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &m);
		for (int j = 0; j < m; ++j) {
			scanf("%d", &t);
			node[i].push_back(t);
		}

	}
	queue<int> q;
	int front, minlevel = -1, cnt = 1;
	q.push(0); level[0] = 0;
	while (!q.empty()) {
		front = q.front();
		q.pop();
		if (node[front].size() == 0) {
			minlevel = level[front];
			break;
		}
		for (int i = 0; i < node[front].size(); ++i) {
			
			level[node[front][i]] = level[front] + 1;
			q.push(node[front][i]);
		}		
	}
	while (!q.empty()) {
		front = q.front();
		q.pop();
		if (level[front] > minlevel) break;
		if (node[front].size() == 0) cnt++;
	}
	printf("%.4f %d\n", pow((1 + r / 100), minlevel)*p, cnt);
	return 0;
}