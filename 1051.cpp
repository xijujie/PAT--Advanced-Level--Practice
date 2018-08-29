#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 1000;
int a[maxn];
bool judge(int m, int n) {
	stack<int> st;
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0, t = 1; t <= n; ++t) {
		if (st.size() == m) return false; 
		st.push(t); //printf("in : %d\n", t);
		while (!st.empty() && st.top() == a[i]) { //printf("out : %d\n", st.top());
			st.pop();
			i++;
		}
	}
	if (st.empty()) return true;
	else return false;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);
	for (int i = 0; i < k; ++i) {
		if (judge(m, n)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}