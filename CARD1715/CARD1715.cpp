// CARD1715.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> A;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        A.push(tmp);
    }

    int sum = 0;
    while (A.size() != 1) {
        int a = A.top();
        A.pop();
        int b = A.top();
        A.pop();

        sum += a + b;
        A.push(a + b);
    }
    cout << sum;
    
}
