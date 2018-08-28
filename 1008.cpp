#include<iostream>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	int n, now = 0, next = -1, total = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &next);
		if (next > now) total += 6 * (next - now);
		else total += 4 * (now - next);
		total += 5;
		now = next;
	}
	printf("%d", total);
	return 0;
}