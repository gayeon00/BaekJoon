#include <iostream>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int map[41][41] = { 0 };

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	int time = 0;
	while (true) {
		time++;
		bool flag = false;

		int tmp_map[41][41] = { 0 };

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {

				if (map[i][j] != 0) {
					int count = 0;
					flag = true;

					for (int k = 0; k < 4; k++) {
						int x = i + dx[k];
						int y = j + dy[k];

						if (x >= 1 && y >= 1 && x <= N && y <= N && map[x][y] == 0) {
							count++;
						}
					}

					if (map[i][j] - count < 0) {
						tmp_map[i][j] = 0;
					} else {
						tmp_map[i][j] = map[i][j] - count;
					}
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j] = tmp_map[i][j];
			}
		}

		if (!flag) {
			cout << time - 1;
			break;
		}
	}
}