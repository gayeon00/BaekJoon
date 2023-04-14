#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
vector<pair<int,int>> blanks;

void read_data() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) blanks.push_back({ i,j });
		}
	}
}

bool check(int row, int col) {
	for (int i = 0; i < 9; i++) {
		if (board[row][i] == board[row][col] && i != col) return false;
		if (board[i][col] == board[row][col] && i != row) return false;
	}

	int boxX = (row / 3) * 3;
	int boxY = (col / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (boxX + i == row && boxY + j == col) continue;
			if (board[boxX + i][boxY + j] == board[row][col]) return false;
		}
	}

	return true;
}

bool finish = false;

void solve(int count) {
	if (count == blanks.size()) {
		finish = true;
		return;
	}

	int row = blanks[count].first;
	int col = blanks[count].second;

	for (int i = 1; i <= 9; i++) {
		board[row][col] = i;
		if (check(row, col)) {
			solve(count + 1);
		}

		if (finish) return;
	}

	board[row][col] = 0;
	return;
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
	//빈칸들 목록을 만들고, 첫 빈칸부터 시작
	//빈칸에 1~9까지 숫자를 일단 넣어봐
	//그리고 그게 규칙에 맞으면 다음 빈칸을 탐색 DFS
	//빈칸 목록 끝에 도달하면 탐색 끝!!
	solve(0);
	print_data();
}