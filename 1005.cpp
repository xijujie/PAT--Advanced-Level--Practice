#include<iostream>
#include<cstring>
int main() {
	//freopen("in.txt", "r", stdin);
	char m[10][6] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	char s[110], r[4];
	int n = 0, i = 0;
	scanf("%s", s);
	while (s[i] != '\0') n += s[i++] - '0';
	sprintf(r, "%d", n);
	printf("%s", m[r[0] - '0']);
	for (i = 1; i < strlen(r); ++i) printf(" %s", m[r[i] - '0']);
	return 0;
}



