#include<cstdio>
#include<cstdio>
const int N = 54;
int deck[N], tmp[N], shuff[N];
char ch[] = "SHCDJ";
int main() {
	freopen("in.txt", "r", stdin);
	int k;
	scanf("%d", &k);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &shuff[i]);
		deck[i] = i;
	}

	while (k--) {
		for (int i = 0; i < N; ++i) tmp[shuff[i] - 1] = deck[i];
		for (int i = 0; i < N; ++i) deck[i] = tmp[i];
	}

	printf("%c%d", ch[deck[0] / 13], deck[0] % 13 + 1);
	for (int i = 1; i < N; ++i) {
		printf(" %c%d", ch[deck[i] / 13], deck[i] % 13 + 1);
	}
	return 0;
}