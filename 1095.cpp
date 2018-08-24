#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;

struct Record {
	string plate;
	int time, status;
} rec[10000], valid[10000];

bool cmp1(Record a, Record b) {
	return a.plate != b.plate ? a.plate < b.plate : a.time < b.time;
}
bool cmp2(Record a, Record b) {
	return a.time < b.time;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, k, hh, mm, ss;
	string s;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		cin >> rec[i].plate;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		cin >> s;		
		rec[i].time = hh * 3600 + mm * 60 + ss;
		if (s == "in") rec[i].status = 1;
		else rec[i].status = 0;
	}

	//将有效记录存入valid[],计算最大停车时间maxtime
	sort(rec, rec + n, cmp1);
	string maxpark = "";
	int time = 0, maxtime = 0, m = 0;
	for (int i = 0; i < n; ++i) {
		if (i + 1 < n && rec[i].plate == rec[i + 1].plate) {
			if (rec[i].status == 1 && rec[i + 1].status == 0 ) {
				valid[m++] = rec[i]; 
				valid[m++] = rec[i + 1];
				time += rec[i + 1].time - rec[i].time;
			}
		}
		else {
			if (time > maxtime) {
				maxtime = time; maxpark = rec[i].plate;
			}
			else if (time == maxtime) maxpark += " " + rec[i].plate;
			time = 0;
		}
	}

	//查询
	sort(valid, valid + m, cmp2);
	int j = 0, num = 0;
	for (int i = 0; i < k; ++i) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		time = hh * 3600 + mm * 60 + ss;
		for (; j < m && valid[j].time <= time; ++j) {
			if (valid[j].status) ++num;
			else --num;
		}
		printf("%d\n", num);
	}
	cout << maxpark;
	printf(" %02d:%02d:%02d\n", maxtime / 3600, (maxtime % 3600) / 60, maxtime % 60);
	return 0;
}

