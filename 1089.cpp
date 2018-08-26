#include<iostream>
#include<algorithm>
const int maxn = 100;
using namespace std;

void print(int seq[], int n) {
	printf("%d", seq[0]);
	for (int i = 1; i < n; ++i) printf(" %d", seq[i]);
}
void merge(int seq[], int n, int step) {
	for (int i = 0; i < n; i += step)
		sort(seq + i, seq + min(i + step, n));
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, i, pos, initseq[maxn], seq[maxn];
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", &initseq[i]);
	for (i = 0; i < n; ++i) scanf("%d", &seq[i]);
	for (i = 0; i < n - 1 && seq[i] <= seq[i + 1]; ++i); //注意此处seq[i]和seq[i + 1]的判断条件为<=
	pos = i + 1; 
	for (i = pos; i < n && seq[i] == initseq[i]; ++i);
	if (i == n) {
		printf("Insertion Sort\n");
		sort(initseq, initseq + pos + 1);
	}
	else {
		printf("Merge Sort\n");
		for (int step = 2;;step *= 2) {
			for (i = 0; i < n; ++i) {
				if (seq[i] != initseq[i]) break;
			}
			merge(initseq, n, step);
			if (i == n) break;
		}	
	}
	print(initseq, n);
	return 0;
}