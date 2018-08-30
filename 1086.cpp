#include<iostream>
#include<string>
#include<stack>
using namespace std;
const int maxn = 30;
int pre[maxn], in[maxn];
int flag = 0;
void postorder(int pl, int pr, int inl, int inr) {
	if (pl > pr) return;
	int root = pre[pl], pos;
	for (pos = inl; in[pos] != root; ++pos);
	postorder(pl + 1, pl + pos - inl, inl, pos - 1);
	postorder(pl + pos - inl + 1, pr, pos + 1, inr);
	if (flag) cout << " "<< root;
	else { 
		cout << root;
		flag = 1; 
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	stack<int> st;
	int n, i = 0, j = 0;
	string s;
	cin >> n;
	for (int k = 0; k < 2*n; ++k) {
		cin >> s;
		if (s == "Push") {
			cin >> pre[i];
			st.push(pre[i++]);
		}
		else {
			in[j++] = st.top();
			st.pop();
		}
	}
	postorder(0, n - 1, 0, n - 1);
	return 0;
}