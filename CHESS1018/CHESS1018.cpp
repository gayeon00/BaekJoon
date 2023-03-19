// CHESS1018.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>

using namespace std;
int M, N;
//"WBWBWB""WBWBWB"이런 식
string board[51];

string w_board[8] = { "WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW" };
string b_board[8] = { "BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB" };

int w_first(int x, int y) {
    int r = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (board[x + i][y + j] != w_board[i][j])
                r++;

    return r;
}

int b_first(int x, int y) {
    int r = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (board[x + i][y + j] != b_board[i][j])
                r++;


    return r;
}

void read_data() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        //Board[i]는 string
        cin >> board[i];
    }
}



void solve() {
    int min = 10000;
    int w = 0, b = 0;
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {

            w = w_first(i, j);
            b = b_first(i, j);

            if (w < b)
                min = (w < min) ? w : min;
            else
                min = (b < min) ? b : min;
        }
    }

    cout << min << "\n";
}



int main() {
    read_data();
    solve();
    //print_data();
    
}
