#include <iostream> 
#include <algorithm>
using namespace std;
const int maxn = 30;
int pre[maxn], post[maxn], in[maxn], num = 0;
bool uni = true;
void inorder(int prl, int prr, int pol, int por) {
	if (prl == prr) {
		in[num++] = pre[prl];
		return;
	}
	int lroot = pre[prl + 1], pos = pol;
	while (post[pos] != lroot) pos++;
	inorder(prl + 1, prl + pos - pol + 1, pol, pos);
	in[num++] = pre[prl];
	if (pos == por - 1) uni = false;
	else inorder(prl + pos - pol + 2, prr, pos + 1, por - 1);
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &pre[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &post[i]);
	inorder(0, n - 1, 0, n - 1);
	if (uni) printf("Yes\n%d", in[0]);
	else printf("No\n%d", in[0]);
	for (int i = 1; i < n; ++i) printf(" %d", in[i]);
	printf("\n");
	return 0;
}