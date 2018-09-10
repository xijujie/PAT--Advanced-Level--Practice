#include <iostream> 
#include <string>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	string d;
	int n;
	cin >> d >> n;
	for (int i = 0; i < n - 1; ++i) {
		string s = "";
		int cnt = 0;
		for (int j = 0; j < d.size(); ++j) {
			cnt++;
			if (j + 1 == d.size() || d[j + 1] != d[j]) {
				s += d[j];
				s += char(cnt + '0');
				cnt = 0;
			}
		}
		d = s;
	}
	cout << d << endl;
	return 0;
}