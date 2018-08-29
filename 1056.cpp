#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1000; 
struct Mouse {
	int w, r;
} mice[maxn];
int order[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", &mice[i].w);
	for (int i = 0; i < n; ++i) scanf("%d", &order[i]);
	int restnum = n, num, tmp, winner, group;
	while (restnum != 1) {
		group = restnum / m + (restnum % m >= 1 ? 1 : 0);
		num = 0;
		for (int i = 0; i < restnum; i += m) {
			tmp = -1;
			for (int j = 0; j < m && i + j < restnum; ++j) {
				mice[order[i + j]].r = group + 1;  //当前老鼠可以分为group组，则该组没有晋级的老鼠排名是group+1
				if (mice[order[i + j]].w > tmp) {
					tmp = mice[order[i + j]].w; winner = order[i + j];
				}
			}
			order[num++] = winner;
		}
		restnum = num;
	}
	mice[winner].r = 1;
	printf("%d", mice[0].r);
	for (int i = 1; i < n; ++i) printf(" %d", mice[i].r);
	return 0;
}