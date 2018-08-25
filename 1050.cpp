#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 10001;
char s1[maxn], s2[maxn];
int a[128] = { 0 };
int main() {
	//freopen("in.txt", "r", stdin);
	cin.getline(s1, maxn);
	cin.getline(s2, maxn);
	int l1 = strlen(s1), l2 = strlen(s2);
	for (int i = 0; i < l2; ++i) a[s2[i]] = 1;

	for (int i = 0; i < l1; ++i) {
		if (a[s1[i]] == 0) printf("%c", s1[i]);
	}
	return 0;
}