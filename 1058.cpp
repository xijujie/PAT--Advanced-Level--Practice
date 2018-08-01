#include<iostream>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	int  g,s,k, g1, s1, k1;
	scanf("%d.%d.%d", &g, &s, &k);
	scanf("%d.%d.%d", &g1, &s1, &k1);
	k += k1;
	if (k >= 29) {
		k %= 29;s += 1;
	}
	s += s1;
	if (s >= 17) {
		s %= 17;g += 1;
	}
	g += g1;
	printf("%d.%d.%d", g, s, k);
	return 0;
}