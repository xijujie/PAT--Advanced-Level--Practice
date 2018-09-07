#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int pt[1001], et[1001], endtime[20];
queue<int> win[20];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, k, q, t = 1;
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 1; i <= k; ++i) scanf("%d", &pt[i]);
	for (int i = 0; i < m && t <= k ; ++i) {
		for (int j = 0; j < n && t <= k; ++j) {
			win[j].push(t);
			et[t] = endtime[j] + pt[t];
			endtime[j] = et[t];
			++t;
		}
	}
	for (; t <= k; ++t) {
		int early = 0;
		for (int j = 1; j < n; ++j) {
			if (et[win[j].front()] < et[win[early].front()]) {
				early = j;
			}
		}
		win[early].push(t);
		et[t] = endtime[early] + pt[t];
		endtime[early] = et[t];
		win[early].pop();
	}
	for (int i = 0; i < q; ++i) {
		scanf("%d", &t);
		if(et[t] + 480 - pt[t] >= 17*60) printf("Sorry\n");
		else {
			printf("%02d:%02d\n", (et[t] + 480)/60, (et[t] + 480)%60);
		}
		
	}
	return 0;
}