#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct Stform {
	string s;
	int k;
};
Stform change(string s, int n) {
	Stform ans;
	ans.s = "0.";
	int pos, i, cnt = 0, l = s.size();
	for (i = 0; i < l && s[i] == '0'; ++i);//ȥ��ǰ������0
	for (pos = i; pos < l && s[pos] != '.'; ++pos);//С����λ��
	ans.k = pos - i;
	if (pos == i) {
		for (i = pos + 1; i < l && s[i] == '0'; ++i) ans.k--; //С������һ����Ϊ0��λ��
		if (i == l) ans.k = 0;
	}
	for (; cnt < n && i < l; ++i) {
		if (s[i] != '.') {
			ans.s += s[i]; cnt++;
		}
	}
	for (; cnt < n; ++cnt) ans.s += '0'; //����λʱ�ں��油0
	return ans;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	Stform f1 = change(s1, n), f2 = change(s2, n);
	if (f1.k == f2.k && f1.s == f2.s) cout << "YES " << f1.s << "*10^" << f1.k;
	else cout << "NO " << f1.s << "*10^" << f1.k << " " << f2.s << "*10^" << f2.k;
	return 0;
}
