#include<iostream>

double pol[2001] = { 0 }, a[1001] = { 0 };
int main() {
	//freopen("in.txt", "r", stdin);
	int k1, k2, e, count = 0;
	double c;
	scanf("%d", &k1);
	while (k1--) {
		scanf("%d%lf", &e, &c);
		a[e] = c;
	}
	scanf("%d", &k2);
	while (k2--) {
		scanf("%d%lf", &e, &c);
		for (int i = 0; i <= 1000; ++i) {
			if (a[i] != 0) {
				pol[e + i] += c * a[i];
			}
		}
	}
	for (int i = 0; i <= 2000; ++i) {
		if (pol[i] != 0) {
			count++;
		}
	}

	printf("%d", count);
	for (int i = 2000; i >= 0; --i) {
		if (pol[i] != 0) {
			printf(" %d %.1f", i, pol[i]);
		}
	}
	return 0;
}