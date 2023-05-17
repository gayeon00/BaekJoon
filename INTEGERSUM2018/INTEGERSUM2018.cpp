// INTEGERSUM2018.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    int count = 1;
    int start_index = 1;
    int end_index = 1;
    int sum = 1;

    while (end_index != N) {
        if (sum == N) {
            end_index++;
            sum += end_index;
            count++;
        } else if (sum < N) {
            end_index++;
            sum += end_index;
        } else {
            sum -= start_index;
            start_index++;
        }
    }

    cout << count;

}
