#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000;
struct Mooncake {
	double inventory, price;
} m[maxn];

bool cmp(Mooncake a, Mooncake b) {
	return a.price > b.price;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, d;
	double tmp, profit = 0;
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; ++i) scanf("%lf", &m[i].inventory);
	for (int i = 0; i < n; ++i) { 
		scanf("%lf", &tmp);
		m[i].price = tmp / m[i].inventory;
	}
	sort(m, m + n, cmp);
	tmp = 0;
	for (int i = 0; i < n; ++i) {
		if (m[i].inventory + tmp <= d) {
			profit += m[i].inventory * m[i].price;
			tmp += m[i].inventory;
		}
		else {
			profit += (d - tmp) * m[i].price;
			break;
		}
	}
	printf("%.2f", profit);
	return 0;

}