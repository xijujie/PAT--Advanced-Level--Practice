#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 10000;
struct Node {
	int num = 0, m = 0, a = 0, fa = -1;
} node[maxn];
double avg[maxn];
vector<int> family;
int Find(int u) {
	if (node[u].fa < 0) return u;
	return node[u].fa = Find(node[u].fa);
}
void Union(int u, int v) {
	int ru = Find(u), rv = Find(v);
	if (ru == rv) return;
	if (rv < ru) node[ru].fa = rv;
	else node[rv].fa = ru;
}
bool cmp(int a, int b) {
	return avg[a] != avg[b] ? avg[a] > avg[b]:a < b;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, id, f, m, k, t, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &id, &f, &m);
		node[id].num = 1;
		if (f != -1) {
			node[f].num = 1;
			Union(id, f);
		}
		if (m != -1) {
			node[m].num = 1;
			Union(id, m);
		}
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &t);
			node[t].num = 1;
			Union(id, t);
		}
		scanf("%d%d", &node[id].m, &node[id].a);
	}
	for (int i = 0; i < maxn; ++i) {
		if (node[i].num) {
			int r = Find(i);
			if (r != i) {
				node[r].num += node[i].num;
				node[r].m += node[i].m;
				node[r].a += node[i].a;
			}
			else {
				family.push_back(i);
				cnt++;
			}
		}
	}
	for (int i = 0; i < family.size(); ++i) avg[family[i]] = 1.0*node[family[i]].a / node[family[i]].num;
	sort(family.begin(), family.end(), cmp);
	printf("%d\n", cnt);
	for (int i = 0; i < family.size(); ++i) 
		printf("%04d %d %.3f %.3f\n", family[i], node[family[i]].num, 1.0*node[family[i]].m / node[family[i]].num, avg[family[i]]);
	return 0;
}