#include<iostream>
#include<string>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	string unlocked, locked, str;
	int h, m, s, tmp, in = 24 * 3600 + 1, out = -1;
	while (n--) {
		cin >> str;
		scanf("%d:%d:%d", &h, &m, &s);
		tmp = h * 3600 + m * 60 + s;
		if (tmp < in) {
			in = tmp;
			unlocked = str;
		}
		scanf("%d:%d:%d", &h, &m, &s);
		tmp = h * 3600 + m * 60 + s;
		if (tmp > out) {
			out = tmp;
			locked = str;
		}
	}
	cout << unlocked << " " << locked;
	return 0;
}