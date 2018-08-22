#include<iostream>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	int a, b, d, i = 0, s[7];
	cin >> a >> b;
	d = a + b;
	if (d == 0) cout << '0';
	else {
		if (d < 0) {
			d = abs(d);
			cout << '-';
		}
		while (d) {
			s[i++] = d % 10;
			d /= 10;
		}
		int t = 0;
		for (int k = i - 1; k >= 0; --k) {
			cout << s[k];
			if (k % 3 == 0 && k - 1 >= 0) cout << ',';
		}
		
	}
	return 0;
}