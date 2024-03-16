#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class info {
public:
	int x, y, num;
	info(int x, int y, int num) {
		this->x = x;
		this->y = y;
		this->num = num;
	}
};

int N, W, H, tot, res;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };


void countBricks(int newArr[][12]) {
	int cnt = 0;
	for (int m = 0; m < H; m++) for (int k = 0; k < W; k++) if (newArr[m][k] > 0) cnt++; // 남은 벽돌 개수 세기
	res = min(res, cnt);
}

void gravity(int newArr[][12]) { // 남은 벽돌들 재정렬
	stack<int> brick; // 재정렬 위해 벽돌 종류 저장
	for (int j = 0; j < W; j++) {
		for (int i = 0; i < H; i++) if (newArr[i][j] > 0) brick.push(newArr[i][j]);
		for (int i = H - 1; i >= 0; i--) {
			if (!brick.empty()) {
				newArr[i][j] = brick.top(); // 밑에서부터 벽돌 채워 넣음
				brick.pop();
			} else newArr[i][j] = 0; // 나머지는 0으로 채워 넣음
		}
	}
}

void crash(int x, int y, int num, int newArr[][12]) {
	newArr[x][y] = 0; // Mark the brick as destroyed

	for (int dir = 0; dir < 4; ++dir) { // Explore all 4 directions
		int nx = x, ny = y;

		for (int step = 1; step < num; step++) { // Move 'power - 1' steps in each direction
			nx += dx[dir];
			ny += dy[dir];

			if (nx >= 0 && nx < H && ny >= 0 && ny < W && newArr[nx][ny] > 0) {
				crash(nx, ny, newArr[nx][ny], newArr); // Recursive call if another brick is found
			}
		}
	}
}

void dfs(int arr[][12], int n) { // 맨 위의 벽돌 찾기 - dfs
	if (n == N) {
		countBricks(arr);
		return;
	}
	for (int j = 0; j < W; j++) { // 각 열마다 맨 위의 벽돌 찾기
		int i = -1;
		while (true) if (++i == H || arr[i][j] > 0) break; // 범위를 벗어나거나 벽돌이면 나온다
		if (i == H) continue; // 벽돌이 없으면 다음 열로 이동

		int newArr[15][12] = { 0 };
		copy(&arr[0][0], &arr[0][0] + 15 * 12, &newArr[0][0]); // 이차원 배열 복사 후 사용
		crash(i, j, newArr[i][j], newArr);
		gravity(newArr);
		dfs(newArr, n + 1);
	}
	countBricks(arr); // 재귀로 못 넘어가는 경우도 있기 때문에 여기서도 res 갱신 시켜준다.
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> W >> H;

		int arr[15][12] = { 0 };
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> arr[i][j];
			}
		}

		res = 987654321;
		dfs(arr, 0);
		cout << "#" << t << " " << res << "\n";
	}

	return 0;
}