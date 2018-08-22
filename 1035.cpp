#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);	
	int i, n, m = 0;
	string s1, s2;
	vector<string> vec;
	map<char, char> mp = { {'1','@'},{ '0','%' },{ 'l','L' },{ 'O','o' } };
	cin >> n;
	for (i = 0; i < n; ++i) {
		int flag = 0;
		cin >> s1 >> s2 ;
		for (int i = 0; i < s2.size(); ++i) {
			if (mp.find(s2[i]) != mp.end()) {
				s2[i] = mp[s2[i]];
				flag = 1;
			}
		}
		if (flag) {
			++m;
			vec.push_back(s1 + " " + s2);
		}
	}
	if (m == 0) {
		if (n == 1) cout << "There is 1 account and no account is modified";
		else cout << "There are "<< n <<" accounts and no account is modified";
	}
	else {
		cout << m << endl;
		for (int i = 0; i < vec.size(); ++i) cout << vec[i] << endl;
	}

	return 0;
}
