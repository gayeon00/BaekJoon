// ATM11399.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N;
    cin >> N;

    priority_queue<int> q;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        q.push(tmp);
    }

    int idx = 1;
    int result = 0;

    while (!q.empty()) {
        result += q.top() * idx;
        q.pop();
        idx++;
    }

    cout << result;


}