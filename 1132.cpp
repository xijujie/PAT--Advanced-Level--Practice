#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	//freopen("in.txt","r",stdin);
	int n, x, y, t;
	string s;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		s = to_string(t);
		x = stoi(s.substr(0, s.size() / 2));
		y = stoi(s.substr(s.size() / 2));
		if (x && y && t % (x*y) == 0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}