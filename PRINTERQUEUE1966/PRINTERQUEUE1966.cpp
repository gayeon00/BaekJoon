// PRINTERQUEUE1966.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;

        queue<pair<int,int>> q;
        priority_queue<int> pq;
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            if (i == M) {
                q.push({ num,1 });
                pq.push(num);
            } else {
                q.push({ num,-1 });
                pq.push(num);
            }
        }

        int count = 0;
        while (!q.empty()) {
            if (q.front().first != pq.top()) {
                pair<int, int> tmp = q.front();
                q.pop();
                q.push(tmp);
            } else {
                pair<int, int> tmp = q.front();
                q.pop();
                pq.pop();
                count++;
                if (tmp.second == 1) {
                    cout << count;
                    break;
                }
            }
        }
    }
}
