#include<iostream>
#include<algorithm>
using namespace std;

struct Student {
	int id;
	int g[4];
} stu[2000];
int sturank[1000000][4] = { 0 };
int course;

bool cmp(Student a, Student b) {
	return a.g[course] > b.g[course];
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, id, g;
	char s[] = "ACME";
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &stu[i].id);
		int t = 0;
		for (int j = 1; j <= 3; ++j) {
			scanf("%d", &g);
			stu[i].g[j] = g;
			t += g;
		}
		stu[i].g[0] = t;
	}

	for (course = 0; course < 4; ++course) {
		sort(stu, stu + n, cmp);
		int r = 1;
		sturank[stu[0].id][course] = 1;
		for (int i = 1; i < n; ++i) {
			if(stu[i].g[course] != stu[i - 1].g[course]) r = i + 1;
			sturank[stu[i].id][course] = r;
		}

	}
	
	while (m--) {
		scanf("%d", &id);
		if (sturank[id][0] == 0) printf("N/A\n");
		else {
			int r = 2001, c;
			for (int i = 0; i < 4; ++i) {
				if (sturank[id][i] < r) {
					r = sturank[id][i];
					c = i;
				}
			}
			printf("%d %c\n", r, s[c]);
		}
	}
	return 0;
}