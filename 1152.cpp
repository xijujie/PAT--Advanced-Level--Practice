#include <iostream>
#include <string>
using namespace std;
bool isprime(int n) {
	if (n == 0 || n == 1) return false;
	for (int i = 2; i*i <= n; ++i) {
		if (n%i == 0) return false;
	}
	return true;
}
int main() {
	int n, k;
	string s, t;
	cin >> n >> k >> s;
	for (int i = 0; i + k - 1 < n; ++i) {
		t = s.substr(i, k);
		if (isprime(stoi(t))) {
			cout << t << endl;
			return 0;
		}
	}
	cout << "404" << endl;
	return 0;
}