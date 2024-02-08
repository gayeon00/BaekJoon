// Nth2075.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int j = 0; j < n*n; j++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
        if (pq.size() > n) pq.pop();
    }

    cout << pq.top();

    return 0;
}