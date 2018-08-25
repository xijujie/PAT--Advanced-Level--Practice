#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 500;
struct Station {
	double p, d;
} st[maxn];
bool cmp(Station a, Station b) {
	return a.d != b.d ? a.d < b.d : a.p < b.p;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, now, next, minnext;
	double maxcap, maxdis, avg, tmp, cap = 0, dis = 0, price = 0;
	scanf("%lf%lf%lf%d", &maxcap, &maxdis, &avg, &n);
	for (int i = 0; i < n; ++i) scanf("%lf%lf", &st[i].p, &st[i].d);
	sort(st, st + n, cmp);

	if (st[0].d > 0) {
		printf("The maximum travel distance = 0.00");return 0;
	}
	for (m = n - 1; m >= 0 && st[m].d >= maxdis; --m);
	st[m + 1].d = maxdis;
	now = 0;
	while (now < m + 1) {
		next = m + 1;
		minnext = m + 1;
		for (int i = now + 1; i <= m && st[i].d <= st[now].d + maxcap * avg; ++i) {
			if (st[i].p < st[now].p) {
				next = i; break;
			}
			if (minnext == m + 1 || st[i].p < st[minnext].p) minnext = i;
		}
		if (next != m + 1) {
			//优先前往比当前更低油价的加油站（在本站加尽量少的油）	
			tmp = (st[next].d - st[now].d) / avg - cap; 
			if (tmp >= 0) {
				price += tmp * st[now].p;	
				cap = 0;
			}
			else cap = fabs(cap);
		}

		else {		
			// 找不到下一个可以到达的加油站，尽量前往终点；或者找不到更低油价的加油站，前往能到达的油价最低的加油站（在本站加尽量多的油）		
			next = minnext;
			if (st[now].d + maxcap * avg >= maxdis) { 
				price += (maxdis - st[now].d) / avg * st[now].p;
				next = m + 1;   //到达终点
			}
			else {
				if (next == m + 1) break;   //无法到达终点
				price += (maxcap - cap)*st[now].p;
				cap = maxcap - (st[next].d - st[now].d) / avg;		
			}
		}		
		now = next; 
	}

	if (now == m + 1) printf("%.2f", price);
	else printf("The maximum travel distance = %.2f", st[now].d + maxcap * avg);
	return 0;
}

