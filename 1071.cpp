#include<iostream>
#include<string>
#include<map>
#include<cctype>
#include<algorithm>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	map<string, int> mp;
	string s = "";
	char ch;
	scanf("%c", &ch);
	while (1) {
		while (!isalnum(ch) && ch != '\n') scanf("%c", &ch);
		if (ch == '\n') break;
		s = "";
		while (isalnum(ch)) {
			if (isupper(ch)) s += tolower(ch);
			else s += ch;
			scanf("%c", &ch);
		}
		mp[s]++;
	}
	int maxcnt = 0;
	for (auto it = mp.begin(); it != mp.end(); ++it){
		if (it->second > maxcnt) {
			maxcnt = it->second;
			s = it->first;
		}
	}
	cout << s << " " << maxcnt;
	return 0;
}