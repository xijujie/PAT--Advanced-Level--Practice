#include<iostream>
using namespace std;
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, t;
	long long uptmp, downtmp, up = 0, down = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld/%lld", &uptmp, &downtmp);	
		up = up * downtmp + uptmp * down;
		down = down * downtmp;
		t = gcd(abs(up), abs(down)); //�����ֵ�����Լ��
		up /= t;
		down /= t;
	}
	if (abs(up) >= down) { 
		printf("%lld", up / down);
		if (down != 1)printf(" %lld/%lld", abs(up) % down, down);
	}	
	else if (up == 0) printf("0"); //ע����Ϊ0�����
	else printf("%lld/%lld", up, down); 
	return 0;
}
