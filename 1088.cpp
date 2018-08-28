#include<iostream>
#include<string>
using namespace std;
struct Fraction {
	long long u, d;
};
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
string change(Fraction a) {
	string s = "";
	int flag = 0;
	if (a.u < 0) { 
		s += "(-"; 
		flag = 1;
	}
	a.u = abs(a.u);
	long long t = gcd(a.u, a.d);
	a.u /= t;
	a.d /= t;
	if (a.u >= a.d) {
		s += to_string(a.u / a.d);
		if (a.d != 1) s += " " + to_string(a.u % a.d) + "/" + to_string(a.d);
	}
	else if (a.u == 0) s += "0";
	else s += to_string(a.u) + "/" + to_string(a.d);
	if (flag) s += ")";	
	return s;
}

int main() {
	//freopen("in.txt", "r", stdin);
	Fraction a, b, ans;
	scanf("%lld/%lld %lld/%lld", &a.u, &a.d, &b.u, &b.d);
	string s1 = change(a), s2 = change(b);
	ans.d = a.d*b.d;
	ans.u = a.u*b.d + b.u*a.d;
	cout << s1 << " + " << s2 << " = " << change(ans) << endl;
	ans.u = a.u*b.d - b.u*a.d;
	cout << s1 << " - " << s2 << " = " << change(ans) << endl;
	ans.u = a.u*b.u;
	cout << s1 << " * " << s2 << " = " << change(ans) << endl;
	if (b.u == 0) cout << s1 << " / " << s2 << " = Inf";
	else {
		ans.u = a.u*b.d;
		ans.d = a.d*b.u; 
		if (ans.d < 0) { //注意计算除法时ans.d可能小于0
			ans.u = -ans.u;
			ans.d = -ans.d;
		}
		cout << s1 << " / " << s2 << " = " << change(ans) << endl;
	}
	return 0;
}
