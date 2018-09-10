#include <iostream> 
#include <algorithm>
#include <unordered_set>
using namespace std;
unordered_set<int> s;
int pre[10000];
int main() {
	//freopen("in.txt", "r", stdin);
	int m, n, k, u, v;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &pre[i]);
		s.insert(pre[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &u, &v);
		auto itu = s.find(u), itv = s.find(v);
		if (itu == s.end() && itv == s.end()) printf("ERROR: %d and %d are not found.\n", u, v);
		else if(itu == s.end()) printf("ERROR: %d is not found.\n", u);
		else if(itv == s.end()) printf("ERROR: %d is not found.\n", v);
		else {
			for (int i = 0; i < n; ++i) {
				k = pre[i];
				if ((u <= k & v >= k) || (u >= k & v <= k)) { //共同最低祖先
					if (u == k) printf("%d is an ancestor of %d.\n", u, v);
					else if(v == k) printf("%d is an ancestor of %d.\n", v, u);
					else printf("LCA of %d and %d is %d.\n", u, v, k);
					break;
				}
			}
		}
	}
	return 0;
}

//#include <iostream> 
//#include <algorithm>
//#include <unordered_set>
//using namespace std;
//unordered_set<int> s;
//int pre[10000];
//struct node {
//	int k;
//	node *l, *r;
//	node(int _k) :k(_k), l(nullptr), r(nullptr) {}
//};
//void creat(node *&root, int l, int r) {
//	if (l > r) return;
//	root = new node(pre[l]);
//	int pos = l + 1;
//	while (pos <= r && pre[pos] < pre[l]) pos++;
//	creat(root->l, l + 1, pos - 1);
//	creat(root->r, pos, r);
//}
//void lca(node *root, int u, int v) {
//	if((u < root->k && v > root->k) || (u > root->k && v < root->k))
//		printf("LCA of %d and %d is %d.\n", u, v, root->k);
//	else if (u == root->k) printf("%d is an ancestor of %d.\n", u, v);
//	else if (v == root->k) printf("%d is an ancestor of %d.\n", v, u);
//	else if (u < root->k && v < root->k) lca(root->l, u, v);
//	else lca(root->r, u, v);		
//}
//int main() {
//	//freopen("in.txt", "r", stdin);
//	int m, n, k, u, v;
//	node *root = nullptr;
//	scanf("%d%d", &m, &n);
//	for (int i = 0; i < n; ++i) {
//		scanf("%d", &pre[i]);
//		s.insert(pre[i]);
//	}
//	creat(root, 0, n - 1);
//	for (int i = 0; i < m; ++i) {
//		scanf("%d%d", &u, &v);
//		auto itu = s.find(u), itv = s.find(v);
//		if (itu == s.end() && itv == s.end()) printf("ERROR: %d and %d are not found.\n", u, v);
//		else if(itu == s.end()) printf("ERROR: %d is not found.\n", u);
//		else if(itv == s.end())printf("ERROR: %d is not found.\n", v);
//		else lca(root, u, v);
//	}
//	return 0;
//}