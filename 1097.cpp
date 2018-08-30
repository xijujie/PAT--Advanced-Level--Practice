#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100000;
struct Node {
	int next, data;
} nodes[maxn];
int remain[maxn], removed[maxn];
int key[10001] = { 0 };
void print(int *addr, int num) {
	if (num != 0) {
		for (int i = 0; i < num - 1; ++i)
			printf("%05d %d %05d\n", addr[i], nodes[addr[i]].data, addr[i + 1]);
		printf("%05d %d -1\n", addr[num - 1], nodes[addr[num - 1]].data);
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, p, ad, ne, d, pre;
	scanf("%d%d", &p, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &ad, &d, &ne);
		nodes[ad].next = ne;
		nodes[ad].data = d;
	}
	int i = 0, j = 0;
	while (p != -1) {
		if (key[abs(nodes[p].data)] == 0) {
			remain[i++] = p;
			key[abs(nodes[p].data)] = 1;
		}
		else removed[j++] = p;
		p = nodes[p].next;
	}
	print(remain,i);
	print(removed,j);
	return 0;
}