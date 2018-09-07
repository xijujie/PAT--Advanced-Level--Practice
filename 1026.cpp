#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 10000, maxk = 101, et = 21 * 3600;
struct Player {
	int vip, at, pt, st = et;
} p[maxn];
struct Table {
	int vip, num = 0, endtime = 8 * 3600;
} table[maxk];
bool cmp1(Player a, Player b) {
	return a.at < b.at;
}
bool cmp2(Player a, Player b) {
	return a.st < b.st;
}
int nextvip(int i, int n) {
	int j = i + 1;
	for (; j < n && p[j].vip == 0; ++j);
	return j;
}
void allotTable(int pid, int tid) {
	p[pid].st = max(p[pid].at, table[tid].endtime);
	table[tid].endtime = p[pid].st + p[pid].pt;
	table[tid].num++;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int n, k, m, hh, mm, ss, pt, t, num = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &pt, &p[i].vip);
		t = hh * 3600 + mm * 60 + ss;
		if (t < et) { //只考虑在21点之前到达的players
			if (pt > 120) pt = 120;
			p[num].at = t;
			p[num++].pt = pt * 60;
		}
	}
	n = num;
	scanf("%d%d", &k, &m);
	int vips = maxk;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &t);
		vips = min(vips, t);
		table[t].vip = 1;
	}
	sort(p, p + n, cmp1);
	int pi = 0, vi = nextvip(-1, n);
	while (pi < n) {
		if (p[pi].vip && pi < vi) {
			++pi;
			continue;
		}
		int i = 1;
		for (int j = 2; j <= k; ++j) {
			if (table[j].endtime < table[i].endtime) i = j;
		}
		if (table[i].endtime >= et) break;

		if (table[i].vip) {
			if (p[pi].vip) { //vip table && vip players
				allotTable(pi, i);
				vi = nextvip(pi, n);
				pi++;
			}
			else {  //vip table && ordinary players
				if (vi < n && p[vi].at <= table[i].endtime) {
					allotTable(vi, i);
					vi = nextvip(vi, n);
				}
				else {
					allotTable(pi, i);
					pi++;
				}
			}
		}
		else { 
			if (p[pi].vip) { //ordinary table && vip players
				int vipi = vips; //vip球员总是优先选择编号最小的空闲VIP球桌而不是编号最小的空闲普通球桌，只有在不存在空闲vip球桌之时，vip球员才等同于普通球员；
				for (int j = vipi + 1; j <= k; ++j) {
					if (table[j].vip && table[j].endtime < table[vipi].endtime) vipi = j;
				}
				if (vipi != maxk && table[vipi].endtime <= p[pi].at) { 
					allotTable(pi, vipi);
				}
				else allotTable(pi, i);
				vi = nextvip(pi, n);
				pi++;
			}
			else { //ordinary table && ordinary players
				allotTable(pi, i);
				pi++;
			}
		}
	}
	sort(p, p + n, cmp2);
	for (int i = 0; i < n; ++i) {
		int at = p[i].at, st = p[i].st, wt = (st - at) / 60 + ((st - at) % 60 >= 30 ? 1 : 0);
		if(st < et) printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",
			at / 3600, (at % 3600) / 60, at % 60, st / 3600, (st % 3600) / 60, st % 60, wt);
	}
	printf("%d", table[1].num);
	for (int i = 2; i <= k; ++i) printf(" %d", table[i].num);
	printf("\n");
	return 0;
}