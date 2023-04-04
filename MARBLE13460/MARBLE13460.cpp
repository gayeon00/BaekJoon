#include <iostream>
#include <queue>

using namespace std;

static char board[11][11];
static bool visited[11][11][11][11];
static int N, M;
static int dx[] = { 1,-1,0,0 };
static int dy[] = { 0,0,1,-1 };

struct step {
	int rx, ry;
	int bx, by;
	int count;
};

void move(int& rx, int& ry, int& rc, int& i) {
	while (board[rx+dx[i]][ry+dy[i]]!='#' && board[rx][ry]!='O') {
		rx += dx[i];
		ry += dy[i];
		rc++;
	}
}

void BFS(int Rx, int Ry, int Bx, int By) {
	queue<step> q;
	q.push({ Rx, Ry, Bx, By, 0 });
	visited[Rx][Ry][Bx][By] = true;
	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int count = q.front().count;
		q.pop();

		if (count >= 10) break;

		for (int i = 0; i < 4; i++) {
			int nrx = rx; int nry = ry;
			int nbx = bx; int nby = by;
			int rc = 0; int bc = 0;
			int ncount = count + 1;


			move(nrx, nry, rc, i);
			move(nbx, nby, bc, i);

			if (board[nbx][nby] == 'O') continue;
			if (board[nrx][nry] == 'O') {
				cout << ncount;
				return;
			}
			if (nbx==nrx && nry==nby) {
				if (rc > bc) {
					nrx -= dx[i];
					nry -= dy[i];
				} else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}

			if (visited[nrx][nry][nbx][nby]) continue;
			q.push({ nrx, nry, nbx, nby, ncount });
			visited[nrx][nry][nbx][nby] = true;
		}
	}

	cout << -1;
}

int main() {
	cin >> N >> M;
	int Rx=0, Ry=0, Bx=0, By=0;

	//입력 받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				Rx = i; Ry = j;
			}
			if (board[i][j] == 'B') {
				Bx = i; By = j;
			}
		}
	}

	BFS(Rx, Ry, Bx, By);
}