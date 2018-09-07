#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 10000;
struct Stu {
	int gp, gm, gf, g;
	string id;
} stu[maxn];
map<string, int> mp;
bool cmp(Stu a, Stu b) {
	if (a.g != b.g) return a.g > b.g;
	return a.id < b.id;
}
int main() {
	//freopen("in.txt","r",stdin);
	int p, m, n, g, t, num = 0;
	char str[21];
	string id;
	scanf("%d%d%d", &p, &m, &n);
	for (int i = 0; i < p; ++i) {
		scanf("%s%d", str, &g);
		id = str;
		if (g >= 200) {
			stu[num] = Stu { g, -1, -1 , 0, id};
			mp[id] = num++;
		}
	}
	for (int i = 0; i < m; ++i) {
		cin >> id >> g;
		if (mp.count(id)) stu[mp[id]].gm = g;
	}
	for (int i = 0; i < n; ++i) {
		cin >> id >> g;
		if (mp.count(id)) {
			t = mp[id];
			stu[t].gf = g;
			if (stu[t].gm > g) stu[t].g = int(0.4*stu[t].gm + 0.6*g + 0.5);
			else stu[t].g = g;
		}
	}
	sort(stu, stu + num, cmp);
	for (int i = 0; i < num && stu[i].g >= 60; ++i)
		printf("%s %d %d %d %d\n", stu[i].id.c_str(), stu[i].gp, stu[i].gm, stu[i].gf, stu[i].g);
	return 0;
}
