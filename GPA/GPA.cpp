// GPA.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
#include <array>

using namespace std;
const int N = 20;
double totalGPA = 0.0;

map<string, double> gradeStandards = {
	{"A+", 4.5},
	{"A0", 4.0},
	{"B+", 3.5},
	{"B0", 3.0},
	{"C+", 2.5},
	{"C0", 2.0},
	{"D+", 1.5},
	{"D0", 1.0},
	{"F", 0.0},
};
struct SubjectScore {
	string subject;
	double weight;
	string grade;
};
array<SubjectScore, N> scoreTable;
double totalWeight = 0.0;



void read_data() {
	string subject;
	double weight;
	string grade;

	for (int i = 0; i < N; i++) {
		cin >> subject >> weight >> grade;

		if (grade != "P") {
			totalWeight += weight;
			scoreTable[i] = { subject, weight, grade };
		}
	}
}

void solve() {
	for (auto eachSubject : scoreTable) {
		totalGPA += eachSubject.weight * gradeStandards[eachSubject.grade];
	}
	totalGPA /= totalWeight;
}

void print_data() {
	cout << totalGPA;
}

int main() {
	read_data();
	solve();
	print_data();
}
