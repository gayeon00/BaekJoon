// ROBOT14503.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int r, c, d;
};

int N, M;
int Map[50][50];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
Point p;



void read_data() {
    cin >> N >> M;
    cin >> p.r >> p.c >> p.d;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Map[i][j];
        }
    }
}

void solve() {
    int result = 0;

    queue<Point> q;
    q.push(p);

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (Map[curr.r][curr.c] == 0) { //현재 위치가 청소를 안했다면
            Map[curr.r][curr.c] = 2;
            result++;
        }
        
        for (int i = 0; i < 4; i++) { //반시계방향으로 돌기
            Point next;

            next.d = (curr.d + 3 - i) % 4;
            next.r = curr.r + dx[next.d];
            next.c = curr.c + dy[next.d];

            if (next.r < 0 || next.c < 0 || next.r >= N || next.c >= M
                || Map[next.r][next.c] != 0) continue; //범위 벗어나거나 청소할 필요가 없는 경우

            q.push(next);
            break; //로봇이 큐에 하나만 존재해야함!
        }

        if (q.empty()) { //청소되지 않은 빈칸이 없는 경우
            Point next;
            next.r = curr.r - dx[curr.d];
            next.c = curr.c - dy[curr.d];
            next.d = curr.d;

            if (next.r < 0 || next.c < 0 || next.r >= N || next.c >= M
                || Map[next.r][next.c] == 1) { //범위를 벗어나거나 벽인 경우 멈추기!
                break;
            }

            q.push(next);
        }
    }
    cout << result;
}

int main(){
    read_data();
    solve();
}
