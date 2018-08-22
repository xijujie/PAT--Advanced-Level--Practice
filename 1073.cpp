#include <iostream>
#include <cstring>
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);

	int ef = 0, i = 0, e;
	char ch, s[10000];	
	if (getchar() == '-') printf("-");
	while ((ch = getchar()) != 'E') {
		if (ch != '.') s[i++] = ch;
	}
	s[i] = '\0';
	if (getchar() == '-') ef = 1;
	scanf("%d", &e);
	//printf("%s%d\n", s, e);

	if (ef) {
		if (e == 0) printf("%c.%s", s[0], s + 1);
		else {
			printf("0.");
			while (e && --e) printf("0");
			printf("%s", s);
		}
	}
	else {
		e = e - strlen(s) + 1;
		if (e >= 0) {
			printf("%s", s);
			while (e--) printf("0");
		}
		else {
			for (i = 0; i < strlen(s) + e; ++i) printf("%c", s[i]);
			printf(".%s", s + i);
		}
	}
	return 0;
}