#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	string s;
	cin >> s;
	int l = s.size(), np = 0, nt = 0, ans = 0;
	//对每一个A计算左边P的个数和右边T的个数的乘积并累加；
	for (int i = 0; i < l;++i) {
		if (s[i] == 'P') np++;
	}
	for (int i = l - 1; i >= 0; --i) {
		if (s[i] == 'T') nt++;
		else if (s[i] == 'P') np--;
		else ans = (ans + np * nt) % 1000000007;		
	}		
	cout << ans;
	return 0;
}