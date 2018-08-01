#include<cstdio>
#include<cstdlib>

double pol[1001] = { 0 };
int main() {
	//freopen("in.txt", "r", stdin);
	int k1, k2, e, count = 0;
	double c;
	scanf("%d", &k1);
	while(k1--) {
		scanf("%d%lf", &e, &c);
		pol[e] += c;
	}
	scanf("%d", &k2);
	while (k2--) {
		scanf("%d%lf", &e, &c);
		pol[e] += c;
	}
	for (int i = 1000; i >= 0; --i) {
		if (pol[i] != 0) 
			count++;
	}

	printf("%d", count);
	for (int i = 1000; i >= 0; --i) {
		if (pol[i] != 0) 
			printf(" %d %.1f", i, pol[i]);	
	}
	return 0;
}