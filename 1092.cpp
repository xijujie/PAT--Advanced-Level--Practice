#include<iostream>
#include<string>
#include<cctype>
using namespace std;
const int maxn = 128;
int main() {
	freopen("in.txt", "r", stdin);
	int a[maxn] = { 0 }, miss = 0;
	string s, s1;
	cin >> s >> s1;	
	for (int i = 0; i < s.size(); ++i) ++a[s[i]];
	for (int i = 0; i < s1.size(); ++i) {
		if (a[s1[i]] > 0) --a[s1[i]];
		else ++miss;
	}
	if (miss) printf("No %d", miss);
	else printf("Yes %d", s.size() - s1.size());
	return 0;
}