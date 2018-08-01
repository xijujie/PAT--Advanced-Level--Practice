#include<iostream>
#include <string>
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	int n, b, s[31], i = 0, l = 0;
	cin >> n >> b;
	if (n == 0) cout << "Yes\n0";
	else {
		while (n) {
			s[l++] = n % b;
			n /= b;
		}
		for (; i < l / 2 && s[i] == s[l - 1 - i]; ++i);
		if (i < l / 2) cout << "No\n" << s[l - 1];
		else cout << "Yes\n" << s[l - 1];
		for (int i = l - 2; i >= 0; --i) cout << " " << s[i];
		return 0;
	}
}

