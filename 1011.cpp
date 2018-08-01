#include<iostream>
int main() {
	//freopen("in.txt", "r", stdin);
	double tmp, ans = 1.0;
	int k = 3;
	char s[] = "WTL";
	while (k--) {
		double t = 0.0;
		int j;
		for (int i = 0; i < 3; ++i) {
			scanf("%lf", &tmp);
			if (tmp > t) {
				t = tmp;
				j = i;
			}
		}
		printf("%c ", s[j]);
		ans *= t;
	}
	
	printf("%.2f", (0.65 * ans - 1) * 2);
	return 0;
}