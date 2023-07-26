// COIN11047.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;

    int A[10];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int sum = 0, cnt = 0;
    for (int i = N - 1; i >= 0; i--) {
        while (sum + A[i] <= K) {
            sum += A[i];
            cnt++;
        }
    }
    cout << cnt;
}
