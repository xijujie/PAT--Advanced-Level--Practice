#include <iostream> 
#include <algorithm>
#include <set>
using namespace std;
int mp[50001];
struct node {
	int item, cnt;
	node(int i, int c) : item(i), cnt(c) {}
	bool operator< (const node &a) const {
		return cnt != a.cnt ? cnt > a.cnt : item < a.item;
	}
};
set<node> rec;
int main() {
	//freopen("in.txt", "r", stdin);
	int n, k, t, cnt = 1;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		if (i != 0) {
			printf("%d:", t);
			for (auto it = rec.begin(); it != rec.end(); ++it) printf(" %d", it->item);
			printf("\n");
		}
		auto it = rec.find(node(t, mp[t]));
		if (it != rec.end()) rec.erase(it);
		rec.insert(node(t, ++mp[t]));
		if (rec.size() > k) rec.erase(--rec.end());
	}
	return 0;
}