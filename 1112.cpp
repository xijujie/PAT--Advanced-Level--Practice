#include <iostream> 
#include <cstring>
using namespace std;
int stuck[128], print[128]; 
int main() {
	//freopen("in.txt", "r", stdin);
	char s[1001], str[1001];
	int l, k, cnt = 0, num = 0;
	scanf("%d%s", &k, s);
	l = strlen(s);
	char ch = s[0];
	for (int i = 0; i < l ; ++i) {
		cnt++;
		if (i + 1 == l || s[i + 1] != ch ) {
			if (cnt % k) stuck[s[i]] = 1;
			cnt = 0;
			if(i + 1 < l) ch = s[i + 1];
		}
	}
	for (int i = 0; i < l; ++i) {
		str[num++] = s[i];
		if (stuck[s[i]] == 0 ) {
			if (print[s[i]] == 0) {
				printf("%c", s[i]);
				print[s[i]] = 1;
			}
			i += k - 1;
		}
	}
	str[num] = '\0';
	printf("\n%s\n", str);
	return 0;
}