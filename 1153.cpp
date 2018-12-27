#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <cstring>
using namespace std;

struct Stu {
	string id;
	int si, g;
} stu[10000];
struct Site {
	int nt, ns;
} site[1000];
map<char, int> mp = { { 'A', 0 },{ 'B', 1 },{ 'T', 2 } };
vector<int> level[3];
int nt[1000];

bool cmp1(int a, int b) {
	if (stu[a].g != stu[b].g) return stu[a].g > stu[b].g;
	else return stu[a].id < stu[b].id;
}
bool cmp2(int a, int b) {
	if (nt[a] != nt[b]) return nt[a] > nt[b];
	else return a < b;
}
int main() {
	int n, m, num, k, t;
	string s;
	cin >> n >> m;
	for (num = 0; num < n; ++num) {
		cin >> stu[num].id >> stu[num].g;
		level[mp[stu[num].id[0]]].push_back(num);
		stu[num].si = stoi(stu[num].id.substr(1, 3));
		site[stu[num].si].nt++;
		site[stu[num].si].ns += stu[num].g;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> k >> s;
		printf("Case %d: %d %s\n", i, k, s.c_str());
		if (k == 1) {
			t = mp[s[0]];
			sort(level[t].begin(), level[t].end(), cmp1);
			for (int j = 0;j < level[t].size(); ++j) {
				printf("%s %d\n", stu[level[t][j]].id.c_str(), stu[level[t][j]].g);
			}
			if (level[t].size() == 0) printf("NA\n");
		}
		else if (k == 2) {
			t = stoi(s);
			if (site[t].nt)
				printf("%d %d\n",site[t].nt, site[t].ns);
			else printf("NA\n");
		}
		else {
			vector<int> v;
			memset(nt, 0, sizeof(nt));
			for (int j = 0; j < num; ++j) {
				if (stu[j].id.substr(4,6) == s) {
					nt[stu[j].si]++;
				}
			}
			for (int j = 0; j < 1000; ++j) {
				if (nt[j]) v.push_back(j);
			}
			sort(v.begin(), v.end(), cmp2);
			for (int j = 0; j < v.size(); ++j) 
				printf("%d %d\n", v[j], nt[v[j]]);
			if (v.size() == 0) printf("NA\n");
		}
	}
	return 0;
}