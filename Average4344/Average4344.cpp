// Average4344.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int C;
vector<vector<int>> scores;

void read_data() {
	cin >> C;
	for (int i = 0; i < C; i++) {
		int N;
		cin >> N;

		int temp;
		vector<int> tmpVector;
		for (int j = 0; j < N; j++) {
			cin >> temp;
			tmpVector.push_back(temp);
		}
		scores.push_back(tmpVector);
	}
}

void solve() {
	for (auto scoreOfClass : scores) {

		int avgScore, sumScores = 0;
		for (auto eachScore : scoreOfClass) {
			sumScores += eachScore;
		}
		avgScore = sumScores / scoreOfClass.size();

		int countAboveAvg = 0;
		for (auto eachScore : scoreOfClass) {
			if (eachScore > avgScore) countAboveAvg++;
		}

		cout << fixed;
		cout.precision(3);
		cout << ((double)countAboveAvg/scoreOfClass.size())*100 << "%\n";
	}
}

int main() {
	read_data();
	solve();
}
