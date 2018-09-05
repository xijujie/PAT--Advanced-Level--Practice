#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 10000, maxk = 100, st = 8 * 3600, et = 17 * 3600;
struct Node {
	int a, p;
} node[maxn];
int endtime[maxk];
bool cmp(Node &a, Node &b) {
	return a.a < b.a;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, k, hh, mm, ss, t, p, num = 0, wait = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &p);
		t = hh * 3600 + mm * 60 + ss;
		if (p > 60) p = 60;
		p *= 60;
		if (t <= et) {
			node[num].a = t;
			node[num++].p = p;
		}
	}
	sort(node, node + num, cmp);
	if (num == 0) {
		printf("0.0\n");
		return 0;
	}
	for (int i = 0; i < k; ++i) endtime[i] = st;
	for (int i = 0; i < num; ++i) {
		int win = 0;
		for (int j = 1; j < k; ++j) {
			if (endtime[j] < endtime[win]) {
				win = j;
			}
		}
		if (endtime[win] > node[i].a) {
			wait += endtime[win] - node[i].a;
			endtime[win] += node[i].p;
		}
		else {
			endtime[win] = node[i].a + node[i].p;
		}
	}
    printf("%.1f\n", wait/60.0/num);
	return 0;
}