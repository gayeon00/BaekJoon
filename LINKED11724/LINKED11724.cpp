// LINKED11724.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> A;
vector<bool> visited;
int cnt = 0;

void read_data() {
    cin >> N >> M;
    A.resize(N + 1);
    visited = vector<bool>(N + 1, false);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

void DFS( int v){
    if (visited[v]) return;

    visited[v] = true;
    for (int i : A[v]) {
        if (visited[i] == false) {
            DFS(i);
        }
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) { //방문 안했다면
            cnt++;
            DFS(i);
        }
    }
}

void print_data() {
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    read_data();
    solve();
    print_data();
}
