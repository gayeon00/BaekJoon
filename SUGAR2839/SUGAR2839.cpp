// SUGAR2839.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int min = 2000;
    for (int x = 0; x < 2000; x++) {
        for (int y = 0; y < 2000; y++) {
            if (5 * x + 3 * y == N && min>(x+y)) {
                min = x + y;
            }
        }
    }
    min < 2000 ? cout << min : cout << -1;
    return 0;
}