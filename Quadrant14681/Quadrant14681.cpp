// Quadrant14681.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int x, y, result;
void read_data();
void solve();
void print_data();

int main() {
    read_data();
    solve(); 
    print_data();
    
}

void read_data() {
    cin >> x >> y;
}

void solve() {
    if (x > 0 && y > 0) {
        result = 1;
    }else if (x < 0 && y > 0) {
        result = 2;
    }else if (x < 0 && y < 0) {
        result = 3;
    }else {
        result = 4;
    }
}

void print_data() {
    cout << result;
}