#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 100000;
struct Record {
	char name[9];
	int age, worth;
} rec[maxn], que[maxn];

bool cmp(Record a, Record b) {
	if (a.worth != b.worth) return a.worth > b.worth;
	else if (a.age != b.age) return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, k, m, amin, amax, num = 0, age[200] = { 0 };
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%s%d%d", rec[i].name, &rec[i].age, &rec[i].worth);
	sort(rec, rec + n, cmp);
	for (int i = 0; i < n; ++i) {
		if (age[rec[i].age] < 100) {
			++age[rec[i].age];
			que[num++] = rec[i];
		}
	}

	for (int i = 0; i < k; ++i) {
		printf("Case #%d:\n", i + 1);
		scanf("%d%d%d", &m, &amin, &amax);
		int t = 0;
		for (int j = 0; j < num && t < m; ++j) {
			if (que[j].age >= amin && que[j].age <= amax) {
				printf("%s %d %d\n", que[j].name, que[j].age, que[j].worth);
				++t;
			}
		}
		if (t == 0) printf("None\n");
	}
	return 0;
}

// �����д���ֱ�Ӳ��ҵ�ʱ����Ե�2��ʱ��250ms
// ����n��m�Ĳ�ֵ���󣬿��Խ�����֮�вƸ�ֵǰ100���˴��������飬100��֮��Ŀ��Զ���
// ������ѯʱ�併�ͣ����Ե�2��ʱ��90ms


