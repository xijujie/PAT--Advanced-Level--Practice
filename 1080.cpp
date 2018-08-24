#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

struct Student {
	int id, ge, gi, g, rank, choice[5];
} stu[40000];
int quota[100], lastStudent[100], num[100] = { 0 }; //每个学校的招生额度，当前招收的最后一名学生，当前已招收的人数
vector<vector<int> > school(100); //每个学校具体招收的学生编号

bool cmp(Student a, Student b) {
	return a.g != b.g ? a.g > b.g:a.ge > b.ge;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, k, r = 1;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i) scanf("%d", &quota[i]);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &stu[i].ge, &stu[i].gi);
		for (int j = 0; j < k; ++j)  scanf("%d", &stu[i].choice[j]);
		stu[i].g = stu[i].ge + stu[i].gi;
		stu[i].id = i;
	}
	sort(stu, stu + n, cmp);
	stu[0].rank = r;
	for (int i = 1; i < n; ++i) {
		if (stu[i].g != stu[i - 1].g || stu[i].ge != stu[i - 1].ge) r = i + 1;
		stu[i].rank = r;
	}

	memset(lastStudent, -1, sizeof(lastStudent));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			int sc = stu[i].choice[j];
			if (num[sc] < quota[sc] || (lastStudent[sc] >= 0 && stu[lastStudent[sc]].rank == stu[i].rank)) {
				school[sc].push_back(stu[i].id);
				lastStudent[sc] = i;
				++num[sc];
				break;
			}
		}
	}
	
	for (int i = 0; i < m; ++i) {
		if (!school[i].empty()) {
			sort(school[i].begin(), school[i].end());
			printf("%d", school[i][0]);
			for (int j = 1; j < school[i].size(); ++j) printf(" %d", school[i][j]);
		}
		printf("\n");
	}
	return 0;
}

