#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct Record {
	char name[21];
	int dd, hh, mm, line, time;
} rec[1000];


bool cmp(Record a, Record b) {
	int s = strcmp(a.name, b.name);
	return s != 0 ? s < 0 : a.time < b.time;
}

int cal(int *rate, Record a) {
	int res = rate[a.hh] * a.mm + rate[24] * 60 * a.dd;
	for (int h = 0; h < a.hh; ++h) res += rate[h] * 60;
	return res;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, name, month, sum = 0;
	int rate[25];
	char s[21];
	for (int i = 0; i < 24; ++i) { 
		scanf("%d", &rate[i]);
		sum += rate[i];
	}
	rate[24] = sum;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s %d:%d:%d:%d %s", rec[i].name, &month, &rec[i].dd, &rec[i].hh, &rec[i].mm, s);
		rec[i].time = rec[i].dd * 24 * 60 + rec[i].hh * 60 + rec[i].mm;
		if (s[1] == 'n') rec[i].line = 1;
		else rec[i].line = 0;	
	}
	sort(rec, rec + n, cmp);

	int t = 0, on = -1, printCnt = 1;
	double ct = 0;
	for (int i = 0; i < n; ++i) {
		int s = strcmp(rec[i].name, rec[t].name);
		if (s != 0) {
			if (ct != 0) printf("Total amount: $%.2f\n", ct);
			t = i; on = -1; ct = 0; printCnt = 1;
		}

		if (rec[i].line) on = i;
		else if (on >= 0) {
			if (printCnt) printf("%s %02d\n", rec[i].name, month);
			printCnt = 0;
			double money = 0.01*(cal(rate, rec[i]) - cal(rate, rec[on]));
			int time = rec[i].time - rec[on].time;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", 
				rec[on].dd, rec[on].hh, rec[on].mm, rec[i].dd, rec[i].hh, rec[i].mm, time, money);
			ct += money;
			on = -1;
		}
	}
	if (ct != 0) printf("Total amount: $%.2f\n", ct);
	return 0;
}

//计算费用时可以分别从00:00 : 00到dd : hh : mm计算再相减
//也可以不断将起始时间加1直至终止时间累加每分钟的费用
//double money = 0; 
//int mm = rec[on].mm, hh = rec[on].hh, dd = rec[on].dd;
//while (mm < rec[i].mm || hh < rec[i].hh || dd < rec[i].dd) {
//	++mm;
//	money += 0.01 * rate[hh];
//	if (mm == 60) { mm = 0; ++hh; }
//	if (hh == 24) { hh = 0; ++dd; }
//}
