// GEAR14891.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

void rotate(int idx, int dir, string gears[5]) {
    if (dir == 1) {
        char tmp = gears[idx][7];
        for (int i = 6; i >= 0; i--) {
            gears[idx][i + 1] = gears[idx][i];
        }
        gears[idx][0] = tmp;
    } else {
        char tmp = gears[idx][0];
        for (int i = 1; i < 8; i++) {
            gears[idx][i - 1] = gears[idx][i];
        }
        gears[idx][7] = tmp;
    }
}

void calculate(string gears[5]) {
    int answer = 0;
    if (gears[1][0] == '1') {
        answer += 1;
    }
    if (gears[2][0] == '1') {
        answer += 2;
    }
    if (gears[3][0] == '1') {
        answer += 4;
    }
    if (gears[4][0] == '1') {
        answer += 8;
    }
    cout << answer;
}

int main() {
    string gears[5];

    for (int i = 1; i <= 4; i++) {
        cin >> gears[i];
    }

    int K;
    cin >> K;
    
    for (int i = 0; i < K; i++) {
        int idx, dir;
        cin >> idx >> dir;

        bool visited[5] = { false };
        vector<pair<int, int>> mlist;
        queue<pair<int, int>> q;
        q.push(make_pair(idx, dir));
        visited[idx] = true;
        mlist.push_back(make_pair(idx, dir));
        while (!q.empty()) {
            pair<int, int> now = q.front();
            q.pop();

            int ndx = now.first;
            int ndir = now.second;
            if (ndx + 1 <= 4 && gears[ndx][2] != gears[ndx+1][6] && !visited[ndx + 1]) {
                q.push(make_pair(ndx + 1, -1 * ndir));
                visited[ndx + 1] = true;
                mlist.push_back(make_pair(ndx + 1, -1 * ndir));
            }

            if (ndx - 1 >= 1 && gears[ndx - 1][2] != gears[ndx][6] && !visited[ndx - 1]) {
                q.push(make_pair(ndx - 1, -1 * ndir));
                visited[ndx - 1] = true;
                mlist.push_back(make_pair(ndx - 1, -1 * ndir));
            }
        }

        for (auto m : mlist) {
            rotate(m.first, m.second, gears);
        }
    }

    calculate(gears);
}
