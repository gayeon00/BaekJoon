// MIN11003.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <deque>

using namespace std;
typedef pair<int, int> Node;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, L;
    cin >> N >> L;
    deque<Node> myDeque;
    
    for (int i = 0; i < N; i++) {
        int now;
        cin >> now;

        while (myDeque.size() && myDeque.back().second > now) {
            myDeque.pop_back();
        }

        myDeque.push_back(Node(i, now));

        if (myDeque.front().first <= i - L) {
            myDeque.pop_front();
        }

        cout << myDeque.front().second << ' ';
    }
}
