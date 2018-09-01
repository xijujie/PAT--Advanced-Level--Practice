#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100;
int initseq[maxn], seq[maxn];
int main() {
	//freopen("in.txt", "r", stdin);
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", &initseq[i]);
	for (i = 0; i < n; ++i) scanf("%d", &seq[i]);
	for (i = 1; i < n && seq[i] >= seq[i - 1]; ++i);
	for (j = i; j < n && seq[j] == initseq[j]; ++j);
	if (j == n) {
		printf("Insertion Sort\n");
		sort(seq, seq + i + 1);
	}
	else {
		printf("Heap Sort\n");
		sort(initseq, initseq + n);
		for (i = n - 1; i >= 0 && seq[i] == initseq[i]; --i);
		swap(seq[0], seq[i]);
		int child;
		for (j = 0; j * 2 + 1 < i;) {
			child = j * 2 + 1;
			if (j * 2 + 2 < i && seq[j * 2 + 2] > seq[child]) child = j * 2 + 2;
			if (seq[j] >= seq[child]) break;
			swap(seq[j], seq[child]);
			j = child;
		}
	}
	printf("%d", seq[0]);
	for (i = 1; i < n; ++i) printf(" %d", seq[i]);
	return 0;
}