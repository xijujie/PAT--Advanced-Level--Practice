//排序所给序列即为中序遍历的结果
//对数组表示的二叉树进行中序遍历，遍历过程中将数字从小到大填入数组即得到结果
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


//也可以根据完全二叉树结点数，求出根结点在中序中对应的下标，并将根节点填入层序数组对应的位置
//分别对左右子树递归
//#include<iostream>
//#include<vector>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//const int maxn = 1000;
//int in[maxn], cbt[maxn + 1], p[11];
//void levelorder(int start, int n, int h, int index) { 
//	//start左端点，n结点数，h除最后一层的层数, index根结点在cbt数组中的下标
//	if (n == 0) return;
//	if (n == 1) {
//		cbt[index] = in[start];
//		return;
//	}
//	int lastnum = n - (p[h] - 1); //h+1层的结点数
//	int	ll = p[h - 1];//h+1层最多可以拥有的属于左子树的结点数
//	int ln = p[h - 1] - 1 + min(ll, lastnum); //左子树的结点数
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