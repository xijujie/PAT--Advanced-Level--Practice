//114ms
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int maxn = 10000;
int in[maxn], pre[maxn];
struct node {
	int k;
	node *father;
};
map<int, node*> mp;
map<int, int> pos;
void creat(int inl, int inr, int pl, int pr, node *father) {
	if (inl > inr) return;
	node *root = new node;
	root->k = pre[pl];
	root->father = father;
	mp[root->k] = root;
	int inpos = pos[pre[pl]];
	creat(inl, inpos - 1, pl + 1, pl + inpos - inl, root);
	creat(inpos + 1, inr, pl + inpos - inl + 1, pr, root);
}
int main() {
	//freopen("in.txt","r",stdin);
	int n, m, u, v, root;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &in[i]);
		pos[in[i]] = i;
	}
	for (int i = 0; i < n; ++i) scanf("%d", &pre[i]);
	creat(0, n - 1, 0, n - 1, nullptr);
	root = pre[0];
	for (int k = 0; k < m; ++k) {
		scanf("%d%d", &u, &v);
		auto f1 = mp.find(u), f2 = mp.find(v);
		if (f1 == mp.end() && f2 == mp.end()) printf("ERROR: %d and %d are not found.\n", u, v);
		else if (f1 == mp.end()) printf("ERROR: %d is not found.\n", u);
		else if (f2 == mp.end()) printf("ERROR: %d is not found.\n", v);
		else {
			vector<int> v1, v2;
			node *p = f1->second, *q = f2->second;
			while (p->k != root) {
				v1.push_back(p->k);
				p = p->father;
			}
			v1.push_back(root);
			while (q->k != root) {
				v2.push_back(q->k);
				q = q->father;
			}
			v2.push_back(root);
			int i = v1.size() - 1, j = v2.size() - 1;
			for (; i >= 0 && j >= 0 && v1[i] == v2[j]; --i, --j);
			if (v1[i + 1] == u) printf("%d is an ancestor of %d.\n", u, v);
			else if (v1[i + 1] == v) printf("%d is an ancestor of %d.\n", v, u);
			else printf("LCA of %d and %d is %d.\n", u, v, v1[i + 1]);
		}
	}
	return 0;
}


//310ms
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <map>
//using namespace std;
//const int maxn = 10000;
//int in[maxn], pre[maxn];
//struct node {
//	int k;
//	node *l, *r;
//	node(int _k) :k(_k), l(nullptr), r(nullptr){}
//};
//map<int, int> pos;
//int main() {
//	//freopen("in.txt","r",stdin);
//	int n, m, u, v;
//	scanf("%d%d", &m, &n);
//	for (int i = 0; i < n; ++i) {
//		scanf("%d", &in[i]);
//		pos[in[i]] = i;
//	}
//	for (int i = 0; i < n; ++i) scanf("%d", &pre[i]);
//	for (int k = 0; k < m; ++k) {
//		scanf("%d%d", &u, &v);
//		auto f1 = pos.find(u), f2 = pos.find(v);
//		if (f1 == pos.end() && f2 == pos.end()) printf("ERROR: %d and %d are not found.\n", u, v);
//		else if (f1 == pos.end()) printf("ERROR: %d is not found.\n", u);
//		else if (f2 == pos.end()) printf("ERROR: %d is not found.\n", v);
//		else {
//			int pu = f1->second, pv = f2->second, pk;
//			for (int i = 0; i < n; ++i) {
//				pk = pos[pre[i]];
//				if ((pu <= pk && pv >= pk) || (pu >= pk && pv <= pk)) { 
//					if (pu == pk) printf("%d is an ancestor of %d.\n", u, v);
//					else if (pv == pk) printf("%d is an ancestor of %d.\n", v, u);
//					else printf("LCA of %d and %d is %d.\n", u, v, pre[i]);
//					break;
//				}
//			}
//		}	
//	}
//	return 0;
//}


//550ms
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <map>
//using namespace std;
//const int maxn = 10000;
//int in[maxn], pre[maxn];
//map<int, int> pos;
//void lca(int inl, int inr, int preRoot, int u, int v) {
//	if (inl > inr) return;
//	int inRoot = pos[pre[preRoot]], inU = pos[u], inV = pos[v];
//	if (inU < inRoot && inV < inRoot) lca(inl, inRoot - 1, preRoot + 1, u, v);
//	else if (inU > inRoot && inV > inRoot) lca(inRoot + 1, inr, preRoot + inRoot - inl + 1, u, v);
//	else if (inU == inRoot) printf("%d is an ancestor of %d.\n", u, v);
//	else if (inV == inRoot) printf("%d is an ancestor of %d.\n", v, u);
//	else printf("LCA of %d and %d is %d.\n", u, v, pre[preRoot]);
//}
//int main() {
//	//freopen("in.txt","r",stdin);
//	int n, m, u, v;
//	scanf("%d%d", &m, &n);
//	for (int i = 0; i < n; ++i) { 
//		scanf("%d", &in[i]); 
//		pos[in[i]] = i;  
//	}
//	for (int i = 0; i < n; ++i) scanf("%d", &pre[i]);
//	for (int i = 0; i < m; ++i) {
//		scanf("%d%d", &u, &v);
//		if (pos.count(u) == 0 && pos.count(v) == 0) printf("ERROR: %d and %d are not found.\n", u, v);
//		else if (pos.count(u) == 0) printf("ERROR: %d is not found.\n", u);
//		else if (pos.count(v) == 0) printf("ERROR: %d is not found.\n", v);
//		else lca(0, n - 1, 0, u, v);
//	}
//	return 0;
//}

