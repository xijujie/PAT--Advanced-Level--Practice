#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
	int d, ne, order, r;
} node[100000];
int a[100000];
bool cmp(int a, int b) {
	return node[a].r != node[b].r ? node[a].r<node[b].r : node[a].order<node[b].order;
}
int main() {
	//freopen("in.txt","r",stdin);
	int p, n, k, ad, d, ne, num = 0;
	scanf("%d%d%d", &p, &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &ad, &d, &ne);
		node[ad].d = d;
		node[ad].ne = ne;
		if (node[ad].d < 0) node[ad].r = 0;
		else if (node[ad].d <= k) node[ad].r = 1;
		else node[ad].r = 2;
	}
	while (p != -1) {
		node[p].order = num;
		a[num++] = p;
		p = node[p].ne;
	}
	sort(a, a + num, cmp);
	for (int i = 0; i < num - 1; ++i) {
		printf("%05d %d %05d\n", a[i], node[a[i]].d, a[i + 1]);
	}
	printf("%05d %d -1\n", a[num - 1], node[a[num - 1]].d);
	return 0;
}