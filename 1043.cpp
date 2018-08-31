#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1000;
int pre[maxn], post[maxn], num = 0;
int judge(int l, int r, int ismirror) {
	if (l > r) return true;
	int root = pre[l], pos = l + 1;
	if (ismirror == 0) {
		for (; pos <= r && pre[pos] < root; ++pos);
		for (int i = pos + 1; i <= r; ++i) {
			if (pre[i] < root) return false;
		}
	}
	else {
		for (; pos <= r && pre[pos] >= root; ++pos);
		for (int i = pos + 1; i <= r; ++i) {
			if (pre[i] >= root) return false;
		}
	}
	int jl = judge(l + 1, pos - 1, ismirror), jr = judge(pos, r, ismirror);
	post[num++] = root;
	return jl && jr;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &pre[i]);
	if (n == 1) printf("YES\n%d", pre[0]);
	else {
		int flag = pre[1] < pre[0] ? judge(0, n - 1, 0) : judge(0, n - 1, 1);
		if (flag) {
			printf("YES\n%d", post[0]);
			for (int i = 1; i < num; ++i) printf(" %d", post[i]);
		}
		else printf("NO\n");
	}
	return 0;
}