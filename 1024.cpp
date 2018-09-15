#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	string s, t;
	int k, step = 0;
	cin >> s >> k;
	t = s; reverse(t.begin(), t.end());
	while (s != t && step < k) {
		int carry = 0, l = s.size();
		for (int i = s.size() - 1; i >= 0; --i) {
			s[i] += t[i] - '0' + carry;
			carry = 0;
			if (s[i] > '9') {
				s[i] -= 10; 
				carry = 1;
			}
		}
		if (carry) s = '1' + s;
		step++;
		t = s; reverse(t.begin(), t.end());
	}
	cout << s << endl << step;
	return 0;
}
