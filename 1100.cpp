#include<iostream>
#include<string>
#include<map>
#include<cctype>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	int n, t, i;
	char ch;
	string s;
	string s1[] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	string s2[] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" }; 
	map<string, int> mp1, mp2, mp;
	for (i = 0; i < 13; ++i) { 
		mp1[s1[i]] = i;
		mp2[s2[i]] = i;
		mp[s1[i]] = i;
		if(i != 0) mp[s2[i]] = i * 13;
	}
	cin >> n;
	cin.get();
	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		//注意 13对应“tam”而非“tam tret” 
		if (isdigit(s[0])) {
			t = stoi(s);
			if(t % 13 == 0)  cout << s2[t / 13] << endl;
			else if (t / 13 == 0) cout << s1[t % 13] << endl;
			else cout << s2[t / 13] << " " << s1[t % 13] << endl;
		}
		else {		
			if (s.size() == 3) cout << mp[s] << endl;
			else cout << mp2[s.substr(0, 3)] * 13 + mp1[s.substr(4)] << endl;			
		}
	}
	return 0;
}
