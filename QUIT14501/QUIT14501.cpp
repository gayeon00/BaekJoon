#include <iostream>

using namespace std;

int main() {
	/*
	i번째 날에 대해
	퇴사까지 일을 다 못끝내면 D[i] = D[i+1]
	다 끝낼 수 있어서 하게 되면 D[i] = max(D[i+1], P[i]+D[i+T[i]])
	*/

	int N;
	cin >> N;

	pair<int,int> schedule[16];
	for (int i = 1; i <= N; i++) {
		cin >> schedule[i].first >> schedule[i].second;
	}

	int D[17] = { 0 };
	for (int i = N; i > 0; i--) {
		if (i + schedule[i].first > N + 1) D[i] = D[i + 1];
		else {
			D[i] = max(D[i + 1], schedule[i].second + D[i + schedule[i].first]);
		}
	}

	cout << D[1];
}