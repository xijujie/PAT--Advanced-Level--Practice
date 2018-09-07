#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s, tmp;
int main() {
	//freopen("in.txt","r",stdin);
	cin >> s;
	int k, cnt = 0;
	for (k = 0; k < 10; ++k) {
		tmp = s;
		reverse(tmp.begin(), tmp.end());
		if (s == tmp) {
			cout << s << " is a palindromic number.\n";
			break;
		}
		cnt = 0;
		cout << s << " + " << tmp << " = ";
		for (int i = s.size() - 1; i >= 0; --i) {
			s[i] += tmp[i] - '0' + cnt;
			cnt = 0;
			if (s[i] > '9') {
				s[i] -= 10;
				cnt = 1;
			}
		}
		if (cnt) s = "1" + s;
		cout << s << endl;
	}
	if (k == 10) cout << "Not found in 10 iterations.\n";
	return 0;
}