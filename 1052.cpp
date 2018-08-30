#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100000;
struct Node {
	int next, key;
} nodes[maxn];
int addr[maxn];
bool cmp(int a, int b) {
	return nodes[a].key < nodes[b].key;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, p, ad, ne, key, num = 0;
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &ad, &key, &ne);
		nodes[ad].next = ne;
		nodes[ad].key = key;
	}
	while (p != -1) {
		addr[num++] = p;
		p = nodes[p].next;
	}
	sort(addr, addr + num, cmp);
	if (num != 0) {
		printf("%d %05d\n", num, addr[0]);
		for (int i = 0; i < num - 1; ++i)
			printf("%05d %d %05d\n", addr[i], nodes[addr[i]].key, addr[i + 1]);
		printf("%05d %d -1\n", addr[num - 1], nodes[addr[num - 1]].key);
	}
	else printf("0 -1\n");
	return 0;
}