// BINOM11050.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;


int main()
{
    int n, k;
    cin >> n >> k;

    int D[11][11];
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j <= i; j++) {

            if (i == j || j == 0 ) {
                D[i][j] = 1;
            } else if (j == 1) {
                D[i][j] = i;
            } else {
                D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
            }
        }
    }

    cout << D[n][k];
    //D[n][k] = D[n-1][k] + D[n-1][k-1]
}
