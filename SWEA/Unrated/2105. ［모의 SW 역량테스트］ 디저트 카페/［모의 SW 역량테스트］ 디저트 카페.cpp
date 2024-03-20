// SWEA2105_DESSERT.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int draw(int x, int y, int d1, int d2, int Map[][21]) {
    //특정 점에 대해 사각형은 이미 정해져있음! 그리고 그 사각형이 유효한지 판단!
    int count = 2 * (d1 + d2);
    //유효하다면 count 업데이트 되겠지!!

    bool eaten[101] = { false };
    //첫 점 먹음
    eaten[Map[x][y]] = true;

    for (int i = 1; i <= d1; i++) {
        int nx = x + i, ny = y - i;
        if (eaten[Map[nx][ny]]) return 0;
        else {
            eaten[Map[nx][ny]] = true;
        }
    }   

    for (int i = 1; i <= d2; i++) {
        int nx = x + i, ny = y + i;
        if (eaten[Map[nx][ny]]) return 0;
        else {
            eaten[Map[nx][ny]] = true;
        }
    }

    for (int i = 1; i <= d1; i++) {
        int nx = x + d2 + i, ny = y + d2 - i;
        if (eaten[Map[nx][ny]]) return 0;
        else {
            eaten[Map[nx][ny]] = true;
        }
    }

    for (int i = 1; i < d2; i++) {
        int nx = x + d1 + i, ny = y - d1 + i;
        if (eaten[Map[nx][ny]]) return 0;
        else {
            eaten[Map[nx][ny]] = true;
        }
    }

    return count;
}

int moveRec(const int& N, int Map[][21]) {
    int result = 0;
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            for (int d1 = 1; d1 <= N; d1++) {
                for (int d2 = 1; d2 <= N; d2++) {
                    if (x + d1 + d2 > N) continue;
                    if (1 + d1 > y) continue;
                    if (y + d2 > N) continue;

                    //특점 점에 대해 d1,d2로 만들어낸 사각형!
                    result = max(result, draw(x, y, d1, d2, Map));
                }
            }
        }
    }

    return result;
}

void solve( int i) { //각 테스트 데이터에 대해 수행!

    int N;
    int Map[21][21];
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> Map[i][j];
        }
    }

    int result = moveRec(N, Map);
    if (result == 0) result = -1;
    cout << "#" << i + 1 << " " << result << '\n';
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve(i);
    }
}