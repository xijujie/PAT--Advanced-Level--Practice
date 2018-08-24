#include<iostream>
#include<algorithm>
using namespace std;

struct Student {
	char name[11], id[11];
	int grade;
};

bool cmp(Student a, Student b) {
	return a.grade > b.grade;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int i, j, n, low, high, t;
	scanf("%d", &n);
	Student *stu = new Student[n];
	for (int i = 0; i < n; ++i) scanf("%s%s%d", stu[i].name, stu[i].id, &stu[i].grade);
	scanf("%d%d", &low, &high);
	sort(stu, stu + n, cmp);
	for (i = 0; i < n && stu[i].grade > high; ++i);
	for (j = n - 1; j >= 0 && stu[j].grade < low; --j);
	if (j - i + 1 > 0) {
		for (; i <= j; ++i) printf("%s %s\n", stu[i].name, stu[i].id);
	}
	else printf("NONE\n");
	return 0;
}