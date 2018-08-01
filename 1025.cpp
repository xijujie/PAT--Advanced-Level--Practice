#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct Stu {
	char id[14];
	int score;
	int loc;
	int loc_rank;
} stu[100*300];

bool cmp(Stu a, Stu b){
	if (a.score != b.score) return a.score > b.score;
	else return strcmp(a.id, b.id) < 0;
}

int main() {
	int n, m = 0, rank = 1;
	//freopen("in.txt","r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int k, r = 1;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			scanf("%s %d\n", stu[m].id, &stu[m].score);
			//printf("%s %d\n", stu[m].id, stu[m].score);
			stu[m++].loc = i;
		}
		sort(stu + m - k, stu + m, cmp);
		stu[m - k].loc_rank = 1;
		for (int j = m - k + 1, t = 1; j < m; ++j, ++t) {
			if (stu[j].score < stu[j - 1].score) r = t + 1;
			stu[j].loc_rank = r;
		}
	}
	sort(stu, stu + m, cmp);

	printf("%d\n", m);
	for (int i = 0; i < m; ++i) {
		if (i == 0) rank = 1;
		else if (stu[i].score < stu[i - 1].score) rank = i + 1;
		printf("%s %d %d %d\n", stu[i].id, rank, stu[i].loc, stu[i].loc_rank);
	}
	return 0;
}

