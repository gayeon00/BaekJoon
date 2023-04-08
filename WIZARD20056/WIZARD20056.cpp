// WIZARD20056.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

struct Ball {
    int r, c;
    int m, s, d;
};
int dr[] = { -1,-1,0,1,1,1,0,-1 };
int dc[] = { 0,1,1,1,0,-1,-1,-1 };
int N, M, K;
vector<Ball> balls;
vector<int> Map[50][50]; //vector<Ball>을 요소로 가지는 이중배열 

void read_data() {
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int r, c, m,s,d;
        cin >> r >> c;
        cin >> m >> s >> d;
        balls.push_back({ r,c,m,s,d });
        Map[--r][--c].push_back(i);
    }

}

void move() {
    vector<int> tmp[50][50];
    for (int i = 0; i < balls.size(); i++) {
        int d = balls[i].d;
        int s = balls[i].s % N; //N보다 클 수도 있으니까!
        int nr = (balls[i].r + (s * dr[d]) + N) % N;
        int nc = (balls[i].c + (s * dc[d]) + N) % N;

        tmp[nr][nc].push_back(i);
        balls[i].r = nr;
        balls[i].c = nc;
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Map[i][j] = tmp[i][j];
        }
    }
}

void spread() {
    vector<Ball> resultBalls;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (Map[r][c].size() == 0) {
                continue;
            }

            if (Map[r][c].size() == 1) {
                int index = Map[r][c][0];
                resultBalls.push_back(balls[index]);
                continue;
            }

            int totalm = 0, totals = 0;
            bool odd = true, even = true;
            for (auto i : Map[r][c]) {
                totalm += balls[i].m;
                totals += balls[i].s;
                if (balls[i].d % 2 == 0) {
                    odd = false;
                } else {
                    even = false;
                }
            }

            int nm = totalm / 5;
            if (nm == 0) {
                continue;
            }
            int ns = totals / Map[r][c].size();


            if (odd||even) {
                resultBalls.push_back({ r,c,nm,ns,0 });
                resultBalls.push_back({ r,c,nm,ns,2 });
                resultBalls.push_back({ r,c,nm,ns,4 });
                resultBalls.push_back({ r,c,nm,ns,6 });
            } else {
                resultBalls.push_back({ r,c,nm,ns,1 });
                resultBalls.push_back({ r,c,nm,ns,3 });
                resultBalls.push_back({ r,c,nm,ns,5 });
                resultBalls.push_back({ r,c,nm,ns,7 });
            }
        }
    }
    balls = resultBalls;

}


void solve() {
    while (K--) {
        move();
        spread();
    }

    int result = 0;
    for (auto ball : balls) {
        result += ball.m;
    }
    cout << result;
}
int main() {
    read_data();
    solve();

}