#include <iostream>
#include <vector>

using namespace std;

const int N = 9;
int board[N][N] = { 0 };

void read_data() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
}

vector<int> get_possible_nums(int row, int col) {
	//row,col위치에 가능한 숫자 찾기

	vector<int> possible_nums;
	bool used[N + 1] = { false };

	for (int i = 0; i < N; i++) {
		//행에서 탐색
		int num = board[row][i];
		if(num != 0) used[num] = true;
	}

	for (int i = 0; i < N; i++) {
		//열에서 탐색
		int num = board[i][col];
		if (num != 0) used[num] = true;
	}

	int box_row = (row / 3) * 3;
	int box_col = (col / 3) * 3;
	for (int i = box_row; i < box_row + 3; i++) {
		//박스에서 탐색
		for (int j = box_col; j < box_col + 3; j++) {
			int num = board[i][j];
			if (num != 0) used[num] = true;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!used[i]) possible_nums.push_back(i);
	}

	return possible_nums;
}

bool solve(int row, int col) {

	//탐색 완료의 경우 true반환 및 종료
	if (row == N) return true;

	//보드의 row,col위치가 이미 채워져 있는 경우
	if (board[row][col] != 0) {
		//마지막 열인 경우
		if (col == N-1) {
			//다음 행 첫째 열 거를 탐색
			if (solve(row + 1, 0)) return true;
		//마지막 열이 아닌 경우
		} else {
			//다음 열을 탐색
			if (solve(row, col + 1)) return true;
		}
		//틀린 경우 false반환
		return false;
	}

	//보드의 row, col위치가 0인 경우 가능한 수 받아옴
	vector<int> nums = get_possible_nums(row, col);
	for (auto i : nums) {
		board[row][col] = i;
		//마지막 열인 경우
		if (col == N-1) {
			//다음 행 첫째 열 거를 탐색
			if (solve(row + 1, 0)) return true;
			//마지막 열이 아닌 경우
		} else {
			//다음 열을 탐색
			if (solve(row, col + 1)) return true;
		}
		board[row][col] = 0;
	}
	//모든 가능한 수가 틀릴경우 틀림
	return false;
}

void print_data() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	read_data();
	solve(0, 0);
	print_data();
}