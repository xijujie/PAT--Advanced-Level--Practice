//�����������м�Ϊ��������Ľ��
//�������ʾ�Ķ���������������������������н����ִ�С�����������鼴�õ����
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1000;
int a[maxn], cbt[maxn + 1];
int n, num = 0;
void inorder(int root) {
	if (root > n) return;
	inorder(root * 2);
	cbt[root] = a[num++];
	inorder(root * 2 + 1);
}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n);
	inorder(1);
	printf("%d", cbt[1]);
	for (int i = 2; i <= n; ++i) printf(" %d", cbt[i]);
	return 0;
}


//Ҳ���Ը�����ȫ����������������������������ж�Ӧ���±꣬�������ڵ�������������Ӧ��λ��
//�ֱ�����������ݹ�
//#include<iostream>
//#include<vector>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//const int maxn = 1000;
//int in[maxn], cbt[maxn + 1], p[11];
//void levelorder(int start, int n, int h, int index) { 
//	//start��˵㣬n�������h�����һ��Ĳ���, index�������cbt�����е��±�
//	if (n == 0) return;
//	if (n == 1) {
//		cbt[index] = in[start];
//		return;
//	}
//	int lastnum = n - (p[h] - 1); //h+1��Ľ����
//	int	ll = p[h - 1];//h+1��������ӵ�е������������Ľ����
//	int ln = p[h - 1] - 1 + min(ll, lastnum); //�������Ľ����
//	cbt[index] = in[start + ln];
//	levelorder(start, ln, h - 1, 2 * index);   
//	levelorder(start + ln + 1, n - 1 - ln, h - 1, 2 * index + 1); 
//}
//
//int main() {
//	//freopen("in.txt", "r", stdin);
//	int n, h;
//	scanf("%d", &n);
//	for (int i = 0; i < n; ++i) scanf("%d", &in[i]); 
//	sort(in, in + n);
//	for (int i = 0; i <= 10; ++i) p[i] = (int) pow(2, i);
//	for (h = 1; n > p[h] - 1; ++h);
//	levelorder(0, n, h - 1, 1);
//	printf("%d", cbt[1]);
//	for (int i = 2; i <= n; ++i) printf(" %d", cbt[i]);
//	return 0;
//}