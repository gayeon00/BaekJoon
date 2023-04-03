// MARBLE13460.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

using namespace std;

struct step {
	int Rx;  int Ry;
	int Bx; int By;
	int count;
};

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool visited[11][11][11][11];
char Map[11][11];

void move(int& rx, int& ry, int& distance, int& i) {
	while (Map[rx + dx[i]][ry + dy[i]] != '#' && Map[rx][ry] != 'O') {  //현재 위치가 구멍이 되거나 다음위치가 벽이 될 때까지
		rx += dx[i];
		ry += dy[i];
		distance++;
	}
}

void BFS(int Rx, int Ry, int Bx, int By) {
	queue<step> q;
	q.push({ Rx, Ry, Bx, By, 0 });
	visited[Rx][Ry][Bx][By] = true;

	while (!q.empty()) {
		int rx = q.front().Rx;
		int ry = q.front().Ry;
		int bx = q.front().Bx;
		int by = q.front().By;
		int count = q.front().count;
		q.pop();

		if (count >= 10) break;
		for (int i = 0; i < 4; i++) {
			int nrx = rx; int nry = ry;
			int nbx = bx; int nby = by;
			int rc = 0; int bc = 0;
			int ncount = count + 1; //i방향으로 움직이니까

			move(nrx, nry, rc, i); //i방향으로 r움직이기
			move(nbx, nby, bc, i);

			if (Map[nbx][nby] == 'O') continue;
			if (Map[nrx][nry] == 'O') {
				cout << ncount;
				return;
			}
			if (nrx == nbx && nry == nby) {
				if (rc > bc) {
					nrx -= dx[i];
					nry -= dy[i];
				} else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}

			if (visited[nrx][nry][nbx][nby]) continue;
			visited[nrx][nry][nbx][nby] = true;
			q.push({ nrx,nry,nbx,nby,ncount });
		}
	}
	cout << -1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	int Rx = 0; int Ry = 0; int Bx = 0; int By = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 'R') {
				Rx = i; Ry = j;
			} else if (Map[i][j] == 'B') {
				Bx = i; By = j;
			}
		}
	}

	BFS(Rx, Ry, Bx, By);
}