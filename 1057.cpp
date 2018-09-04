#include<iostream>
#include<stack>
using namespace std;
const int maxn = 100001;
#define lowbit(i) ((i)&(-i))
int c[maxn];  //树状数组
stack<int> st;
void update(int x, int v) {
	for (int i = x; i < maxn; i += lowbit(i)) c[i] += v;
}
int getsum(int x) {
	int res = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) res += c[i];
	return res;
}
int findmed() {
	int k = (st.size() + 1) / 2, l = 1, r = maxn, mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (getsum(mid) < k) l = mid + 1;
		else r = mid;
	}
	return l;
}
int main() {
	//freopen("in.txt", "r", stdin);
	char s[11];
	int n, t;  
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		if (s[1] == 'o') {
			if (st.empty()) printf("Invalid\n");
			else {	
				printf("%d\n", st.top());
				update(st.top(), -1);
				st.pop();
			}
		}
		else if (s[1] == 'e') {
			if (st.empty()) printf("Invalid\n");
			else printf("%d\n", findmed());
		}
		else {
			scanf("%d", &t);
			st.push(t);
			update(t, 1);
		}
	}
	return 0;
}

//分块查找 
//#include<iostream>
//#include<stack>
//#include<cmath>
//using namespace std;
//const int maxn = 100001;
//int key[maxn], block[1000];
//stack<int> st;
//int main() {
//	//freopen("in.txt", "r", stdin);
//	int m = (int)sqrt(maxn), n, t, k;  
//	char s[11];
//	scanf("%d", &n);
//	for (int k = 0; k < n; ++k) {
//		scanf("%s", s);
//		if (s[1] == 'o') {
//			if (st.empty()) printf("Invalid\n");
//			else {	
//				printf("%d\n", st.top());
//				key[st.top()]--;
//				block[st.top() / m]--;
//				st.pop();
//			}
//		}
//		else if (s[1] == 'e') {
//			if (st.empty()) printf("Invalid\n");
//			else {
//				int i = 0, j = 0, t = 0, mid = (st.size() + 1) / 2;
//				while (t + block[i] < mid) t += block[i++];
//				j = m * i;
//				while (t + key[j] < mid) t += key[j++];
//				printf("%d\n", j);
//			}
//		}
//		else {
//			scanf("%d", &t);
//			st.push(t);
//			key[t]++;
//			block[t / m]++;	
//		}
//	}
//	return 0;
//}