#include <iostream>
#include <math.h>

using namespace std;

char map[10000][10000];

void draw(int x, int y, int k) {
	if (k == 0) {
		map[x][y] = '*';
		return;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != 1 || j != 1) {
				draw(x + i * pow(3, k - 1), y + j * pow(3, k - 1), k - 1);
			}
		}
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			map[i][j] = ' ';
		}
	}

	int tmp = N;
	int count = 0;
	while (tmp != 0) {
		tmp /= 3;
		count++;
	}

	draw(1, 1, count - 1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}