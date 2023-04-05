// SNAKE3190.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int MAP[100][100];
int N, K, L;
//i로 방향 정하기
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
vector<pair<int, char>> changeDirections;

void turn(int& i, char l) {
    if (l == 'D') {
        i++;
        if (i > 3) i = 0;
    }
    if (l == 'L') {
        i--;
        if (i < 0) i = 3;
    }
}

void read_data() {
    cin >> N >> K;

    //사과 위치 받기

    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        //사과가 있는 곳은 1로 채우기
        MAP[x - 1][y - 1] = 1;
    }

    cin >> L;
    //방향 전환 정보 받기
    for (int i = 0; i < L; i++) {
        int x; char c;
        cin >> x >> c;
        changeDirections.push_back({ x,c });
    }
}

void solve() {
    deque<pair<int, int>> q;
    MAP[0][0] = 2;
    q.push_back({ 0,0 });
    int index=0, time=0;
    int i = 0;
    int x = 0, y = 0;

    while (true) {
        time++;
        int nx = x + dx[i];
        int ny = y + dy[i];

        if ((nx < 0 || ny < 0 || nx >= N || ny >= N )|| MAP[nx][ny] == 2) {
            break;
        }

        //사과 먹을 경우
        if (MAP[nx][ny] == 1) {
            q.push_front({ nx,ny });
            MAP[nx][ny] = 2;
        }
        //빈칸일 경우
        if (MAP[nx][ny] == 0) {
            q.push_front({ nx,ny });
            MAP[nx][ny] = 2;
            MAP[q.back().first][q.back().second] = 0;
            q.pop_back();
        }

        if (index < changeDirections.size()) {
            //바꿀 시간이 되면
            if (time == changeDirections[index].first) {
                turn(i, changeDirections[index].second);
                index++;
            }
        }
        x = nx;
        y = ny;
    }

    cout << time;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    read_data();

    solve();

}