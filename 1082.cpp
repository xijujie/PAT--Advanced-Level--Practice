#include<iostream>
#include<string>
#include<vector>
using namespace std;

string v1[] = { "ling", "yi", "er" ,"san", "si", "wu","liu", "qi", "ba", "jiu" };
string v2[] = { "", " Shi", " Bai"," Qian" };
string v3[] = { "", " Wan", " Yi" };
string s;

void print(int i, int j) {
	int t = j - i;
	for (; j >= i && s[j] == '0'; --j);
	if (j < i) return;
	while (i <= j) {
		if (i != 0) cout << " ";//只要不是首位，均需要先输出空格
		cout << v1[s[i] - '0'];
	    if(s[i] != '0') {
			cout << v2[t]; ++i; --t;
		}
		else {
			while (s[i] == '0'){ ++i; --t; }
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	cin >> s;
	if (s == "0") cout << v1[0]; //0 ling

	int j = s.size() - 1, i = 0;
	if (s[0] == '-') {
		cout << "Fu"; ++i; 
	}

	for (int k = 2; k >= 0; k--) {
		if (j - i + 1 > k*4) {
			print(i, j - k * 4);
			i = j - k * 4 + 1;
			cout << v3[k];
		}
	}
	return 0;
}
	
