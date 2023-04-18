// BUS11404.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int n, m;
long board[101][101];

void read_data() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) board[i][j] = 0;
            //충분히 큰수로 저장 but LONG_MAX등 max로 하믄 안됨!
            //나중에 40번에서 대소비교할때 오버플로우때매 똑바로 비교 안됨
            else board[i][j] = 10000001;
        }
    }

    for (int i = 0; i < m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        if (board[start][end] > cost) {
            board[start][end] = cost;
        }

    }
}

void solve() {
    //D[s][e] = min(D[s][e], D[s][k]+D[k][e])
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i][j] > board[i][k] + board[k][j]){
                    board[i][j] = board[i][k] + board[k][j];

                }
            }
        }
    }
}

void print_data() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] != 10000001) cout << board[i][j] << ' ';
            else cout << 0 << ' ';
            
        }
        cout << '\n';
    }
}

int main() {
    read_data();
    solve();
    print_data();
}
