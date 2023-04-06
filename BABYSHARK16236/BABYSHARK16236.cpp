#include <iostream>
#include <queue>

using namespace std;

struct Point {
	int x, y, d;
};

const int INF = 1000;
int N;
int Map[20][20];
int x, y;//상어 위치
int result;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void read_data() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 9) {
				x = i, y = j;
				Map[i][j] = 0;
			}
		}
	}
}

void solve() {
	int size = 2, cnt = 2;//상어 사이즈
	Point minPt = { x,y,0 };

	do {
		bool visited[20][20] = { false };
		queue<Point> q;
		visited[minPt.x][minPt.y] = true;
		q.push({ minPt.x,minPt.y,0 });
		minPt.d = INF;

		while (!q.empty()) {
			Point curr = q.front();
			q.pop();

			if (curr.d > minPt.d) break;
			if (Map[curr.x][curr.y] > size) continue;
			if (Map[curr.x][curr.y] != 0 && Map[curr.x][curr.y] < size) {
				if (curr.d < minPt.d) {
					minPt = curr;
				} else if (curr.d == minPt.d) {
					if (curr.x < minPt.x) minPt = curr;
					else if (curr.x == minPt.x && curr.y < minPt.y) minPt = curr;
				}
				continue;
			}

			for (int i = 0; i < 4; i++) {
				int nx = curr.x + dx[i];
				int ny = curr.y + dy[i];
				int nd = curr.d + 1;

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (visited[nx][ny]) continue;

				q.push({ nx,ny,nd });
				visited[nx][ny] = true;
			}
		}

		if (minPt.d != INF) {
			result += minPt.d;
			Map[minPt.x][minPt.y] = 0;
			cnt--;
			if (cnt == 0) {
				++size;
				cnt = size;
			}
		}

	} while (minPt.d != INF);

	cout << result;

}

int main() {
	read_data();
	solve();
}