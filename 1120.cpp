#include <iostream> 
#include <set>
using namespace std;
set<int> ans;
int main() {
	//freopen("in.txt", "r", stdin);
	int n, t, sum;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		sum = 0;
		while (t) {
			sum += t % 10;
			t /= 10;
		}
		ans.insert(sum);
	}
	auto it = ans.begin();
	printf("%d\n%d", ans.size(), *it++);
	for (; it != ans.end(); ++it) printf(" %d", *it);
	printf("\n");
	return 0;
}
