#include<iostream>
#include<string>
#include<map>
#include<set>
#include<cctype>
#include<algorithm>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	map<string, set<int>> mp;
	string s;
	int n, m, id;
	char ch;
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d\n", &id);
		for (int j = 0; j < 5; ++j) {
			if (j == 2) {
				while (cin >> s) {
					mp[s].insert(id);
					cin.get(ch);
					if (ch == '\n') break;
				}
			}
			else {
				getline(cin, s);
				mp[s].insert(id);
			}
		}
	}
	scanf("%d\n", &m);
	for (int i = 0; i < m; ++i) {
		getline(cin, s);
		cout << s << endl;
		auto it = mp.find(s.substr(3));
		if (it == mp.end()) printf("Not Found\n");
		else {
			for (auto its = it->second.begin(); its != it->second.end(); ++its)
				printf("%07d\n", *its);  //注意id是7位的
		}
	}
	return 0;
}