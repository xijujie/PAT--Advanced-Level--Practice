#include<cstdio>
#include<cstdlib>
//dis[i] : distance the 1-th ~ i-th 
int dis[100001];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, t, sum, i, j;
	scanf("%d", &n);
	dis[1] = 0;
	for (int i = 1; i < n; ++i) {
		scanf("%d", &t);
		dis[i + 1] = dis[i] + t;
	}
	scanf("%d", &t);
	sum = t + dis[n];

	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &i, &j);
		t = abs(dis[i] - dis[j]);
		printf("%d\n", t < sum - t ? t : sum - t);
	}
	return 0;
}