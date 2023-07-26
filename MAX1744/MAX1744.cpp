// MAX1744.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;

    priority_queue<int> plus;
    priority_queue<int, vector<int>, greater<int>> minus;
    int ones = 0, zeros = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (tmp > 1) {
            plus.push(tmp);
        } else if (tmp < 0) {
            minus.push(tmp);
        } else if (tmp == 1) {
            ones++;
        } else {
            zeros++;
        }
    }

    long sum_plus = 0;
    while (!plus.empty()) {
        int a = 0 , b = 0;
        a = plus.top();
        plus.pop();

        if (!plus.empty()) {
            b = plus.top();
            plus.pop();

            sum_plus += a * b;
        } else {
            sum_plus += a;
        }
    }

    long sum_minus = 0;
    while (!minus.empty()) {
        int a = 0, b = 0;
        a = minus.top();
        minus.pop();

        if (!minus.empty()) {
            b = minus.top();
            minus.pop();

            sum_minus += a * b;
        } else if (zeros == 0) {
            sum_minus += a;
        }
    }

    cout << sum_plus + sum_minus + ones;
}
