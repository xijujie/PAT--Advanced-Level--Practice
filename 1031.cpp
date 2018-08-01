#include<iostream>
#include<string>
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	string str;
	cin >> str;
	int n1, n2, n = str.size(), i;
	n1 = (n + 2) / 3;
	n2 = n1 + (n + 2) % 3;
	for (i = 0; i < n1 - 1; ++i) {
		cout << str[i];
		for (int j = 0; j < n2 - 2; ++j) cout << " ";
		cout << str[n - 1 - i] << endl;
	}
	for (int j = 0; j < n2; ++j) cout << str[i + j];
	cout << endl;
	return 0;
}