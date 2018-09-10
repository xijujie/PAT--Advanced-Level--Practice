#include <iostream> 
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;
const int maxn = 100000;
struct Node {
	double tws;
	int ns;
	string s;
} node[maxn];
unordered_map<string, int> mp;
bool cmp(Node a, Node b) {
	if ((int)a.tws != (int)b.tws) return (int)a.tws > (int)b.tws;
	if (a.ns != b.ns) return a.ns < b.ns;
	return a.s < b.s;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, g, t, num = 0;
	char s1[7], s2[7];
	string s;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s%d%s", s1, &g, s2);
		s = s2;
		for (int j = 0; j < s.size(); ++j) s[j] = tolower(s[j]);
		if (mp.find(s) == mp.end()) {
			t = num;
			mp[s] = num;
			node[num++] = { 0.0, 0, s };	
		}
		else t = mp[s];
		node[t].ns++;
		if (s1[0] == 'A') node[t].tws += g;
		else if (s1[0] == 'B') node[t].tws += g / 1.5;
		else node[t].tws += g * 1.5;	
	}
	sort(node, node + num, cmp);
	printf("%d\n", num);
	int r = 1;
	for (int i = 0; i < num; ++i) {
		if (i != 0 && (int)node[i].tws != (int)node[i - 1].tws) r = i + 1;
		printf("%d %s %d %d\n", r, node[i].s.c_str(), (int)node[i].tws, node[i].ns);
	}
	return 0;
}