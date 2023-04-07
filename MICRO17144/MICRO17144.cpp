// MICRO17144.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

const int INF = 51;

using namespace std;
int R, C, T;
int Map[50][50];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void read_data() {
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> Map[i][j];
        }
    }
}

void spread() {
    int add[50][50] = { 0 };
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (Map[i][j] > 0) {
                int cnt = 0;

                //좌
                if (j - 1 >= 0 && Map[i][j - 1]!=-1) {
                    add[i][j - 1] += Map[i][j] / 5;
                    cnt++;
                }
                //우
                if (j + 1 < C && Map[i][j + 1]!=-1) {
                    add[i][j + 1] += Map[i][j] / 5;
                    cnt++;
                }
                //상
                if (i - 1 >= 0 && Map[i - 1][j]!=-1) {
                    add[i-1][j] += Map[i][j] / 5;
                    cnt++;
                }
                //하
                if (i + 1 < R && Map[i + 1][j]!=-1) {
                    add[i+1][j] += Map[i][j] / 5;
                    cnt++;
                }

                add[i][j] -= cnt * (Map[i][j] / 5);
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            Map[i][j] += add[i][j];
        }
    }
}

void purify_top() {
    int top;
    for (int i = 0; i < R; i++) {
        if (Map[i][0] == -1) {
            top = i;
            break;
        }
    }
    
    //반시계방향으로 한칸 옮기기

    // 아래쪽 행 이동
    for (int i = top-1; i > 0; i--) {
        Map[i][0] = Map[i - 1][0];
    }

    //왼쪽 열 이동
    for (int j = 0; j < C - 1; j++) {
        Map[0][j] = Map[0][j + 1];
    }


    // 위쪽 행 이동
    for (int i = 0; i < top; i++) {
        Map[i][C - 1] = Map[i + 1][C - 1];
    }

    // 오른쪽 열 이동
    for (int j = C - 1; j > 1; j--) {
        Map[top][j] = Map[top][j - 1];
    }

    Map[top][1] = 0;

}

void purify_bottom() {
    int bottom;
    for (int i = 0; i < R; i++) {
        if (Map[i][0] == -1) {
            bottom = i+1;
            break;
        }
    }

    //[bottom][0]은 공기청정기 있으니까 패스
    for (int i = bottom + 1; i < R; i++) {
        Map[i][0] = Map[i + 1][0];
    }

    for (int j = 0; j < C - 1; j++) {
        Map[R - 1][j] = Map[R - 1][j + 1];
    }

    for (int i = R - 1; i > bottom; i--) {
        Map[i][C - 1] = Map[i - 1][C - 1];
    }

    for (int j = C - 1; j > 1; j--) {
        Map[bottom][j] = Map[bottom][j - 1];
    }

    Map[bottom][1] = 0;
}

void purify() {
    purify_top();
    purify_bottom();
}

void solve() {
    while (T--) { //이게 맞나?
        spread();
        purify();
    }

    int sum = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (Map[i][j] != -1) sum += Map[i][j];
        }
    }
    cout << sum;
    
}

int main() {
    read_data();
    solve();
}
