// ABSHEAP11286.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct compare {
    bool operator()(int& a, int& b) {
        if (abs(a) == abs(b)) {
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main() {
    int N;
    cin >> N;

    priority_queue<int, vector<int>, compare> pq;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        if (tmp == 0) {
            if (pq.empty()) {
                cout << 0 << '\n';
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            //queue에 tmp넣기
            pq.push(tmp);
        }
    }
}
