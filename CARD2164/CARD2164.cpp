// CARD2164.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    while (q.size() != 1) {
        //버리기
        q.pop();

        if (q.size() == 1) {
            break;
        }

        //옮기기
        int tmp = q.front();
        q.push(tmp);
        q.pop();
    }

    cout << q.front();
}
