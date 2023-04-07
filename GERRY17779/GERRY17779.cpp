// GERRY17779.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#define INF 100000000

using namespace std;


int N;
int A[21][21];
int sum = 0;

void read_data() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            sum += A[i][j];
        }
    }
}

int mapping(int x, int y, int d1, int d2) {
    int reg[21][21] = { 0 };
    reg[x][y] = 5;
    //1구역 쪽
    for (int i = 1; i <= d1; i++) {
        reg[x + i][y - i] = 5;
        reg[x + d2 + i][y + d2 - i] = 5;
    }

    //2구역 쪽
    for (int i = 1; i <= d2; i++) {
        reg[x + i][y + i] = 5;
        reg[x + d1 + i][y - d1 + i] = 5;
    }

    //1구역 더하기
    int aa=0;
    for (int r = 1; r < x + d1; r++) {
        for (int c = 1; c <= y; c++) {
            if (reg[r][c] == 5) break;
            aa += A[r][c];
        }
    }

    //2구역
    int bb=0;
    for (int r = 1; r <= x + d2; r++) {
        for (int c = N; c >y; c--) { //방향 주의 <- 이 방향으로 채우기
            if (reg[r][c] == 5) break;
            bb += A[r][c];
        }
    }
    //3구역
    int cc=0;
    for (int r = x+d1; r <= N; r++) {
        for (int c = 1; c <y-d1+d2; c++) {
            if (reg[r][c] == 5) break;
            cc += A[r][c];
        }
    }
    //4구역
    int dd=0;
    for (int r = x+d2+1; r <= N; r++) {
        for (int c = N; c >= y - d1 + d2; c--) { //방향 주의
            if (reg[r][c] == 5) break;
            dd += A[r][c];
        }
    }

    //5구역 채우기
    int ee = sum - aa - bb - cc - dd;

    return max(aa,max(bb,max(cc,max(dd,ee)))) - min(aa, min(bb, min(cc, min(dd,ee))));
}

void solve() {
    int result = INF;
    
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            for (int d1 = 1; d1 <= N; d1++) {
                for (int d2 = 1; d2 <= N; d2++) {
                    if (x + d1 + d2 > N) continue;
                    if (1 + d1 > y) continue;
                    if (y + d2 > N) continue;
                    result = min(result, mapping(x, y, d1, d2));
                }
            }
        }
    }

    cout << result;
}


int main() {
    read_data();
    solve();
}
