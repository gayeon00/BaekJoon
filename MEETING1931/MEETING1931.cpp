// MEETING1931.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

struct compare {
    bool operator()(pii& a, pii& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

int N;
priority_queue<pii, vector<pii>, compare> A;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        A.push({ a,b });
    }

    int result = 0, finished = -1;
    while (!A.empty()) {
       
        pii top = A.top();
        A.pop();

        if (finished <= top.first) {
            result++;
            finished = top.second;
           
        }

    }

    cout << result;
}
