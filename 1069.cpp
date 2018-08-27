#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	int n, n1, n2;
	string s1, s2;
	scanf("%d", &n);
	if(n == 6174) printf("7641 - 1467 = 6174\n"); //n=6174时特殊处理
	while (n != 0 && n != 6174) {
		s1 = to_string(n);
		int l = 4 - s1.size(); //注意不足四位的情况
		while (l--) s1 += "0";
		sort(s1.begin(), s1.end());
		s2 = s1;
		reverse(s1.begin(), s1.end());
		n1 = stoi(s1);
		n2 = stoi(s2);
		n = n1 - n2;
		printf("%04d - %04d = %04d\n", n1, n2, n);
	}
	return 0;
}

