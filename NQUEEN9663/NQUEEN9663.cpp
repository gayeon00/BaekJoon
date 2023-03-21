// NQUEEN9663.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;
int N, cnt = 0;
int arr[15];

bool isPossible(int col) {
	for (int i = 0; i < col; i++) {
		if ( arr[i] == arr[col] || (col - i) == abs(arr[col] - arr[i])) {
			return false;
		}
	}
	return true;
}

void nQueen(int depth) {
	if (depth == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		arr[depth] = i;
		if (isPossible(depth)) {
			nQueen(depth + 1);
		}
	}
}


int main() {
	cin >> N;
	nQueen(0);
	cout << cnt << '\n';
}