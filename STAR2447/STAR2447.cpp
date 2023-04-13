#include <iostream>

using namespace std;
char board[7000][7000];

void star(int x, int y, int N) {
	if (N == 1) board[x][y] = '*';
	else {
		for (int i = x; i < x + N; i += N / 3) {
			for (int j = y; j < y + N; j += N / 3) {
				if (i == x + N / 3 && j == y + N / 3) continue;
				
				star(i, j, N / 3);
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 7000; i++) {
		for (int j = 0; j < 7000; j++) {
			board[i][j] = ' ';
		}
	}
	star(0,0,N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}