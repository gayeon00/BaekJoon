// TIME11657.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;
typedef pair<int, int> edge;
int N, M;
vector<vector<edge>> mlist;
vector<int> mdistance;

void read_data() {
    cin >> N >> M;

    mlist.resize(N + 1);
    mdistance.resize(N + 1, INT_MAX);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        mlist[a].push_back({ b,c });
    }
}

void solve() {
    priority_queue<edge, vector<edge>, greater<edge>> q;

    mdistance[1] = 0;
    q.push({ 0,1 });

    while (!q.empty()) {
        edge curr = q.top();
        q.pop();

        for (auto i : mlist[curr.second]) {
            int next = i.first;
            int value = i.second;

            if (mdistance[next] > mdistance[curr.second] + value) {
                mdistance[next] = mdistance[curr.second] + value;
                q.push({ mdistance[next], next });
            }
        }
    }

    vector<int> mdistance2(mdistance);

    q.push({ 0,1 });

    while (!q.empty()) {
        edge curr = q.top();
        q.pop();

        for (auto i : mlist[curr.second]) {
            int next = i.first;
            int value = i.second;

            if (mdistance2[next] > mdistance2[curr.second] + value) {
                mdistance2[next] = mdistance2[curr.second] + value;
                q.push({ mdistance2[next], next });
            }
        }
    }

    bool flag = true;
    for (int i = 2; i <= N; i++) {
        if (mdistance[i] != mdistance2[i]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        for (int i = 2; i <= N; i++) {
            if (mdistance[i] != INT_MAX) cout << mdistance[i] << '\n';
            else cout << -1 << '\n';
        }
    } else {
        cout << -1;
    }

}

int main() {
    read_data();
    solve();
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
