#include<iostream>
#include<ctype.h>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	char s[4][61];
	char day[7][4] = { "MON" ,"TUE" ,"WED" ,"THU" ,"FRI" ,"SAT","SUN" };
	for (int i = 0; i < 4; ++i) scanf("%s", s[i]);
	int i, h;
	for (i = 0;; ++i) {
		//A~G
		if (s[0][i] >= 'A' && s[0][i] <= 'G' && s[0][i] == s[1][i]) {
			printf("%s ", day[s[0][i] - 'A']);
			break;
		}
	}
	for (i = i + 1;; ++i) {
		//0~9,A~N
		if (s[0][i] == s[1][i] && (isdigit(s[0][i])|| (s[0][i] >= 'A' && s[0][i] <= 'N'))) {
			if (isdigit(s[0][i]))  h = s[0][i] - '0';
			else h = s[0][i] - 'A' + 10;
			printf("%02d:", h);
			break;
		}
	}
	for (i = 0;; ++i) {
		//a~z,A~Z
		if (isalpha(s[2][i]) && s[2][i] == s[3][i]) {
			printf("%02d", i);
			break;
		}
	}
	return 0;
}