#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int m, s;
int map[5][5] = { 0 };
int smell[5][5] = { 0 };

int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

int sx[4] = { -1,0,1,0 };
int sy[4] = { 0,-1,0,1 };

struct Fish {
	int x;
	int y;
	int d;
};

Fish shark;

vector<Fish> fishes;
vector<Fish> copy_fishes;
bool visited[5][5] = { false };
int shark_way[3] = { 0 };
int tmp_shark_way[3] = { 0 };

int result = -1;

void read_data() {
	cin >> m >> s;
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;

		map[x][y]++; //물고기 수 세기
		fishes.push_back({ x,y,--d });
	}
	cin >> shark.x >> shark.y;
}

void copy() {
	copy_fishes.clear();
	copy_fishes.assign(fishes.begin(), fishes.end());
}

void move() {
	for (Fish& f : fishes) {
		int x = f.x; int y = f.y; int d = f.d;

		int nd = d;
		int nx = x + dx[nd];
		int ny = y + dy[nd];
		
		//out of range도 아니고, 냄새가 남은 칸도 아니고, 상어가 있는칸도 아니면
		if (!(ny == shark.y && nx == shark.x) && smell[nx][ny] == 0 && (nx > 0 && ny > 0 && nx <= 4 && ny <= 4)) {

			map[x][y]--; //물고기 기존 위치에서 제거
			map[nx][ny]++; //새로운 위치에 넣기
			f.x = nx; f.y = ny; f.d = nd;

		} else {
			nd = (nd + 7) % 8;
			while (d != nd) {
				nx = x + dx[nd];
				ny = y + dy[nd];

				//out of range도 아니고, 냄새가 남은 칸도 아니고, 상어가 있는칸도 아니면
				if (!(ny == shark.y && nx == shark.x) && smell[nx][ny] == 0 && (nx > 0 && ny > 0 && nx <= 4 && ny <= 4)) {

					map[x][y]--; //물고기 기존 위치에서 제거
					map[nx][ny]++; //새로운 위치에 넣기
					f.x = nx; f.y = ny; f.d = nd;
					break;
				}

				nd = (nd + 7) % 8;
			}
		}
	}
}

int count_prey() {
	Fish curr = { shark.x, shark.y }; //상어 현재 위치부터 탐색 시작
	int sum = 0;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < 3; i++) {
			
		int dir = tmp_shark_way[i];
		int nx = curr.x + sx[dir];
		int ny = curr.y + sy[dir];

		if (nx < 1 || ny < 1 || nx>4 || ny>4) {
			return -1;
		}

		if (!visited[nx][ny]) {
			visited[nx][ny] = true;
			sum += map[nx][ny];
		}
		curr = { nx, ny };
	}
	return sum;
}

void DFS(int depth) {
	if (depth == 3) {
		int sum = count_prey();

		if (result < sum) {
			result = sum;
			for (int i = 0; i < 3; i++) {
				shark_way[i] = tmp_shark_way[i];
			}
		}

		return;
	}

	for (int i = 0; i < 4; i++) {
		tmp_shark_way[depth] = i;
		DFS(depth + 1);
	}
}

void shark_move() {
	result = -1;
	DFS(0);

	vector<Fish> tmp;

	for (int i = 0; i < 3; i++) {
		int nx = shark.x + sx[shark_way[i]];
		int ny = shark.y + sy[shark_way[i]];

		if (map[nx][ny] > 0) {
			map[nx][ny] = 0;
			smell[nx][ny] = 3;
		}
		shark = { nx,ny };
	}

	for (Fish& f : fishes) {
		//방금 잡아먹은 물고기만 제외하고 벡터에 넣기
		if (smell[f.x][f.y] != 3) {
			tmp.push_back(f);
		}
	}

	fishes = tmp;


}

void remove_smell() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (smell[i][j] > 0) {
				smell[i][j]--;
			}
		}
	}
}

void paste() {
	for (auto i : copy_fishes) {
		map[i.x][i.y]++;
		fishes.push_back(i);
	}
}

void print_map(string str) {
	cout << str << '\n';
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main() {
	read_data();
	for (int i = 0; i < s; i++) {
		copy();
		move();
		shark_move();
		remove_smell();
		paste();
	}

	int cnt = 0;

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			cnt += map[i][j];
		}
	}
	cout << cnt;
}