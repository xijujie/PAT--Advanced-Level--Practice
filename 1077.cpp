#include<iostream>
#include<string>
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	int n, i, j, k = 0, flag = 0;
	string s, t;
	cin >> n;
	char c = cin.get();
	getline(cin, s);
	while (--n) {
		getline(cin, t);
		for (i = s.size() - 1, j = t.size() - 1; i >= k && j >= 0 && s[i] == t[j]; --i, --j);		
		if (i == s.size() - 1) {
			flag = 1;
			break;
		}
		k = i + 1;
	}
	if (flag) cout << "nai";
	else cout << s.substr(k);
	return 0;
}

//Anime and Manga ¶¯ÂþºÍÂþ»­