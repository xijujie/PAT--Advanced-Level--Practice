#include<iostream>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	int n, now, left, right, ans = 0, k = 1;
	scanf("%d", &n);
	while (n / k) { //�Դӵ͵���ÿһλ�����λΪ1�����ĸ���
		now = (n / k) % 10; //nowΪ��ǰλ������
		left = (n / k) / 10; //leftΪnow����������ֹ��ɵ�����
		right = n % k; //rightΪnow�ұ��������ֹ��ɵ�����
		if (now == 0) ans += left * k;
		else if (now == 1) ans += left * k + right + 1;
		else ans += (left + 1) * k;
		k *= 10;
	}
	printf("%d", ans);
	return 0;
}



//#include<iostream>
//#include<string>
//#include<cmath>
//using namespace std;
//const int l = 10;
//int main() {
//	//freopen("in.txt", "r", stdin);
//	int n, count = 0;
//	int b[l], num[l];
//	b[0] = 0;
//	for (int i = 1, k = 1; i < l; ++i, k *= 10)
//		b[i] = k + 10 * b[i - 1]; //cout << b[i] << endl; ����9��99��999��9999..��Ӧ�Ľ������b[];
//	scanf("%d", &n);
//	string s = to_string(n);
//	int m = s.size(), t = pow(10, m - 1);
//	for (int i = m - 1; i >= 0; --i) {
//		int p = n / t, q = n % t;
//		if (p == 1) count += b[i] + q + 1;
//		else if (p > 1) count += p * b[i] + t;
//		n = q;
//		t /= 10;
//	}
//	printf("%d", count);
//	return 0;
//}