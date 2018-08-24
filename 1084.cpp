#include<iostream>
#include<string>
#include<cctype>
using namespace std;
const int maxn = 128;
int a[maxn] = { 0 };

int main() {
	//freopen("in.txt", "r", stdin);
	string s, s1;
	cin >> s >> s1;
	for (int i = 0; i < s1.size(); ++i) { 
		if (islower(s1[i])) s1[i] = toupper(s1[i]);
		a[s1[i]] = 1;
	}
	for (int i = 0; i < s.size(); ++i) {
		if (islower(s[i])) s[i] = toupper(s[i]);
		if (a[s[i]] == 0) cout << s[i];
		a[s[i]] = 1;
	}

}