#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int r, c, d;
int Map[51][51];
int result = 0;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

struct Node {
	int r;
	int c;
	int d;
};

void read_data() {
	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}
}

void clean() {
	queue<Node> q;
	q.push({ r,c,d });

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		//청소 안된 경우 청소하기
		if (Map[now.r][now.c] != 2) {
			Map[now.r][now.c] = 2;
			result++;
			//cout << result << ": " << now.r << ", " << now.c << ", " << now.d << '\n';
		}

		int flags[4] = { 1,1,1,1 };

		for (int i = 0; i < 4; i++) {
			int nd = (now.d + 3 - i) % 4;

			
			int nr = now.r + dx[nd];
			int nc = now.c + dy[nd];

			//out of range 이거나 벽
			if (nr < 0 || nc < 0 || nr > N - 1 || nc > M - 1 || Map[nr][nc] == 1) {
				flags[i] = 0;
				continue;
			} 
			if (Map[nr][nc] != 2) {
				//cout << "전진\n";
				q.push({ nr,nc,nd });
				break;
			} else {
				flags[i] = 0;
			}
			
		}

		//청소되지 않는 빈칸이 없는 경우 
		if (count(flags, flags + 4, 0) == 4) {
			int nr = now.r - dx[now.d];
			int nc = now.c - dy[now.d];

			if (nr < 0 || nc < 0 || nr > N - 1 || nc > M - 1 || Map[nr][nc] == 1) {
				continue;
			}

			//cout << "후진\n";
			q.push({ nr,nc,now.d });

		}
	}

	cout << result;
}

int main() {
	read_data();
	clean();
}