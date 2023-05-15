// AVG1546.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	int maxScore = 0;
	vector<int> scoreList(N);
	for (int i = 0; i < N; i++) {
		int score;
		cin >> score;
		if (score > maxScore) maxScore = score;

		scoreList[i] = score;
	}

	double result = 0.0;
	for (int i = 0; i < N; i++) {
		result += (double)scoreList[i] / maxScore * 100;
	}

	cout << result / N;

}
