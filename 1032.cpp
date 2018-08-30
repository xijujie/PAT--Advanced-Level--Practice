#include<iostream>
using namespace std;
const int maxn = 100000;
struct Node {
	int next, flag;
} nodes[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, p, q, ad, ne;
	scanf("%d%d%d", &p, &q, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %*c %d", &ad, &ne);
		nodes[ad].next = ne;
		nodes[ad].flag = 0;
	}
	while (p != -1) {
		nodes[p].flag = 1; //该节点在链表1中出现，flag设为1
		p = nodes[p].next;
	}
	while (q != -1) {
		if (nodes[q].flag == 1) break; //发现共用节点
		q = nodes[q].next;
	}
	if(q != -1) printf("%05d", q);
	else printf("-1");
	return 0;
}