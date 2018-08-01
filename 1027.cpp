#include<iostream>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	int k = 3, tmp;
	char c[] = "0123456789ABC";
	cout << "#";
	while (k--) {
		cin >> tmp;
		cout << c[tmp / 13] << c[tmp % 13];
	}
	return 0;
}