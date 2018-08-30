#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100000;
struct Node {
	int data, next;
} nodes[maxn];
int a[maxn];

int main() {
	//freopen("in.txt", "r", stdin);
	int n, k, p, address, data, next, num = 0;
	scanf("%d%d%d", &p, &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &address, &data, &next);
		nodes[address].data = data;
		nodes[address].next = next;
	}
	while (p != -1) {
		a[num++] = p;
		p = nodes[p].next;
	}
	for (int i = 0; i + k <= num; i += k) reverse(a + i, a + i + k);
	for (int i = 0; i < num - 1; ++i) printf("%05d %d %05d\n", a[i], nodes[a[i]].data, a[i + 1]);
	printf("%05d %d -1\n", a[num - 1], nodes[a[num - 1]].data);
	return 0;
}