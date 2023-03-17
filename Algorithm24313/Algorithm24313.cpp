// Algorithm24313.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main() {
    int a0, a1;
    int c;
    int n0;

    cin >> a0 >> a1;
    cin >> c;
    cin >> n0;

    for (int i = n0; i < 10000; i++) {
        if (a0 * i + a1 > c * i) {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
    return 0;
}
