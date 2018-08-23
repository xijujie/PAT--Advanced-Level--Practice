#include<iostream>
#include<algorithm>
using namespace std;

struct Person {
	int id, vg, tg, r;
} people[100000];

bool cmp(Person a, Person b) {
	if (a.r != b.r) return a.r < b.r;
	else if (a.tg != b.tg) return a.tg > b.tg;
	else if (a.vg != b.vg) return a.vg > b.vg;
	else return a.id < b.id;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, low, high, id, vg, tg, m = 0;
	scanf("%d%d%d", &n, &low, &high);
	while (n--) {
		scanf("%d%d%d", &id, &vg, &tg);
		if (vg >= low && tg >= low) {
			people[m].id = id;
			people[m].vg = vg;
			people[m].tg = tg + vg;
			if (vg >= high && tg >= high) people[m].r = 1;
			else if (vg >= high) people[m].r = 2;
			else if (vg >= tg) people[m].r = 3;
			else people[m].r = 4;
			++m;
		}
	}
	printf("%d\n", m);
	sort(people, people + m, cmp);
	for (int i = 0; i < m; ++i) 
		printf("%d %d %d\n", people[i].id, people[i].vg, people[i].tg - people[i].vg);
	return 0;
}