#include <iostream> 
#include <algorithm>
#include <set>
using namespace std;
set<int> s;
int main() {
	//freopen("in.txt", "r", stdin);
	int n, t;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		if (t > 0)  s.insert(t);
	}
	t = 1;
	for (auto it = s.begin(); it != s.end() && *it == t; ++it, ++t);
	printf("%d\n", t);
	return 0;
}