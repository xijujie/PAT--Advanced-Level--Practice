#include<iostream>
#include<string>
using namespace std;
int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	int grade1 = -1, grade2 = 101, grade;
	string female, male, name, id;
	char gender;
	while (n--) {
		cin >> name >> gender >> id >> grade;
		if (gender == 'F' && grade > grade1) {
			grade1 = grade;
			female = name + " " + id;
		}
		else if (gender == 'M' && grade < grade2) {
			grade2 = grade;
			male = name + " " + id;
		}
	}

	if (grade1 < 0) cout << "Absent" << endl;
	else cout << female << endl;
	if (grade2 > 100) cout << "Absent" << endl;
	else cout << male << endl;
	if(grade1 < 0 || grade2 > 100) cout << "NA" << endl;
	else cout << grade1 - grade2 << endl;
	return 0;
}
		