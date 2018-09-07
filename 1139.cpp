#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
const int maxn = 10000;
set<int> adj[maxn], edge;
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, k, u, v, s, d;
	string a, b;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;//ʹ���ַ��������������ж�0000���Ա�
		u = abs(stoi(a)); 
		v = abs(stoi(b));
		if (a.length() == b.length()) {
			adj[u].insert(v);
			adj[v].insert(u);
		}
		edge.insert(u*maxn + v);
		edge.insert(v*maxn + u); //��u-v,v-u����
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d%d", &s, &d);
		vector<pair<int, int> > ans;
		for (auto itu = adj[abs(s)].begin(); itu != adj[abs(s)].end(); ++itu) {
			for (auto itv = adj[abs(d)].begin(); itv != adj[abs(d)].end(); ++itv) {
				u = *itu; v = *itv;
				if (u != abs(d) && v != abs(s) && edge.find(u*maxn+v) != edge.end())  //����Aֱ�ӵ�B����Bֱ�ӵ�A
					ans.push_back(pair<int, int>(u, v));
			}
		}
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); ++i) printf("%04d %04d\n", ans[i].first, ans[i].second);
	}
	return 0;
}