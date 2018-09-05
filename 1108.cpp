#include <iostream>
#include <cstring>
using namespace std;
const int maxl = 40;
int main() {
	//freopen("in.txt", "r", stdin);
	int n, cnt = 0;
	double t, sum = 0.0;
	char a[maxl], b[maxl];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", a);
		int flag = sscanf(a, "%lf", &t);
		if (flag) {
			sprintf(b, "%.2f", t);
			int l = strlen(a);
			for (int j = 0; j < l; ++j) {
				if (a[j] != b[j]) {
					flag = 0; break;
				}

			}
		}
		if (flag && t >= -1000 && t <= 1000) {
			cnt++; sum += t;
		}
		else printf("ERROR: %s is not a legal number\n", a);
	}
	if (cnt == 0) printf("The average of 0 numbers is Undefined\n");
	else if (cnt == 1) printf("The average of 1 number is %.2f\n", sum);
	else printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
	return 0;
}
