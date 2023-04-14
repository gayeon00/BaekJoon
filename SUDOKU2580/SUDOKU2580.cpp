#include <iostream>
#include <vector>

using namespace std;
int board[9][9];

void read_data() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
		}
	}
}
//비어있는 i,j위치에 들어올 수 있는 숫자 구하기
vector<int> getPossibleNums(int x, int y) {
	//같은 열 탐색
	bool numbers[10] = { false };
	for (int j = 0; j < 9; j++) {
		if (board[x][j] == 0) continue;
		numbers[board[x][j]] = true;
	}

	//같은 행 탐색
	for (int i = 0; i < 9; i++) {
		if (board[i][y] == 0) continue;
		numbers[board[i][y]] = true;
	}

	//박스 탐색
	int boxX = (x / 3) * 3;
	int boxY = (y / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[boxX + i][boxY + j] == 0) continue;
			numbers[board[boxX + i][boxY + j]] = true;
		}
	}


	vector<int> possibleNumbs;
	for (int i = 1; i <= 9; i++) {
		if (numbers[i] == false) {
			possibleNumbs.push_back(i);
		}
	}

	return possibleNumbs;
}


bool solve(int x, int y) {

	if (x == 9) return true;

	if (board[x][y] != 0) {
		if (y == 8) {
			if (solve(x + 1, 0)) return true;
		} else {
			if (solve(x, y + 1)) return true;
		}
		return false;
	}

	vector<int> possibleNums = getPossibleNums(x, y);
	for (auto i : possibleNums) {
		board[x][y] = i;
		if (y == 8) {
			if (solve(x + 1, 0)) return true;
		} else {
			if (solve(x, y + 1)) return true;
		}
		board[x][y] = 0;
	}
	return false;
}

void print_data() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main() {
	read_data();
	solve(0,0);
	print_data();
}