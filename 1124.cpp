#include <iostream> 
#include <string>
#include <set>
using namespace std;
string follower[1001];
set<string> ss;
int main() {
	//freopen("in.txt", "r", stdin);
	int m, n, s;
	scanf("%d%d%d", &m, &n, &s);
	for (int i = 1; i <= m; ++i) cin >> follower[i];
	if(s > m) printf("Keep going...\n");
	for (int i = s; i <= m; ) {
		if (ss.find(follower[i]) == ss.end()) {
			ss.insert(follower[i]);
			cout << follower[i] << endl;
			i += n;
		}
		else {
			i++;
			while (i <= m && follower[i] == follower[i - 1]) i++;
		}
	}
	return 0;
}