#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 10001;

struct User {
	int total = -1, perfect = 0, id = 0, score[5] = { -1,-1,-1,-1,-1 };
} u[maxn];

bool cmp(User a, User b) {
	if (a.total != b.total) return a.total > b.total;
	else if (a.perfect != b.perfect) return a.perfect > b.perfect;
	else return a.id < b.id;
}

void print(User u, int k, int r) {
	printf("%d %05d %d", r, u.id, u.total);
	for (int i = 0; i < k; ++i) {
		if (u.score[i] >= 0)  printf(" %d", u.score[i]);
		else printf(" -");
	}
	printf("\n");
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, k, m, id, p, s, full[5];
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < k; ++i) scanf("%d", &full[i]);

	while (m--) {
		scanf("%d%d%d", &id, &p, &s);
		if (u[id].score[p - 1] < s) {
			u[id].id = id;
			u[id].score[p - 1] = s;
		}
		else if (u[id].score[p - 1] == -1 && s == -1) u[id].score[p - 1] = 0;
	}

	for (int i = 1; i <= n; ++i) {
		if (u[i].id > 0) {
			u[i].total = 0;
			for (int j = 0; j < k; ++j) {
				if (u[i].score[j] > 0) u[i].total += u[i].score[j];
				if (u[i].score[j] == full[j]) ++u[i].perfect;
			}
		}
	}
	sort(u + 1, u + n + 1, cmp);

	int r = 1;
	print(u[1], k, r);
	for (int i = 2; i <= n && u[i].total >= 0; ++i) {
		if (u[i].total != u[i - 1].total) r = i;
		print(u[i], k, r);
	}
	return 0;
}

