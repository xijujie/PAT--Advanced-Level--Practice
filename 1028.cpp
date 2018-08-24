#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct Record {
	char name[9];
	int id, grade;
} rec[100000];
int n, c;

bool cmp(Record a, Record b) {	
	if (c == 1) return a.id < b.id;
	else if (c == 2) {
		int s = strcmp(a.name, b.name);
		return s != 0 ? s < 0 : a.id < b.id;
	}
	else return a.grade != b.grade ? a.grade < b.grade : a.id < b.id;
}

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; ++i) scanf("%d%s%d", &rec[i].id, rec[i].name, &rec[i].grade);
	sort(rec, rec + n, cmp);
	for (int i = 0; i < n; ++i) printf("%06d %s %d\n", rec[i].id, rec[i].name, rec[i].grade);
	return 0;
}

