#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//const int maxn = 100000;

bool cmp(string a, string b) {
	return a + b <= b + a; //如果a + b <= b + a，则将a排在b的前面
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, i, l;
	string ans = "";
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; ++i) ans += v[i];
	for (i = 0, l = ans.size(); i < l - 1 && ans[i] == '0'; ++i);//注意结果为0的情况
	for (; i < l; ++i) cout << ans[i];
	return 0;
}

