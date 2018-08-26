#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int ch_n(char ch) {
	return isalpha(ch) ? ch - 'a' + 10 : ch - '0';
}

long long convert(string s, long long r) { 
	long long res = 0;
	int l = s.size();
	for (int i = 0; i < l; ++i) {
		res = r * res + ch_n(s[i]);
		if (res < 0) return -1;//可能会发生溢出；
	}
	return res;
}

int main() {
	//freopen("in.txt", "r", stdin);
	string s1, s2;
	int tag, l, i;
	long long n1, n2, r1, r2, low, high, mid;
	cin >> s1 >> s2 >> tag >> r1;
	if (tag == 2) swap(s1, s2);
	n1 = convert(s1, r1);
	l = s2.size();
	for (low = 1, i = 0; i < l; ++i) //二分查找的r2下界low是n2中数位最大的数加1
		if (ch_n(s2[i]) + 1 > low) low = ch_n(s2[i]) + 1; 
	high = l == 1 ? low : n1; //如果l>=2，则上界high=n1；如果l==1,因为要输出最小的结果，所以令high=low
	while (low <= high) {
		mid = (low + high) / 2;
		n2 = convert(s2, mid);
		if (n2 == n1) {
			break;
		}
		else if (n2 == -1 || n2 > n1) high = mid - 1;
		else low = mid + 1;
	}
	if (low > high) cout << "Impossible";
	else cout << mid;
	return 0;
}