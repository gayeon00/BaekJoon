// DFSBFS1260.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, M, V;
vector<vector<int>> A;
vector<bool> visited;

void read_data() {
    cin >> N >> M >> V;
    A.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

void DFS(int v) {
    cout << v << ' ';
    visited[v] = true;

    for (int i : A[v]) {
        if (!visited[i]) DFS(i);
    }
}

void BFS(int v) {
    visited[v] = true;
    queue<int> myQueue;
    myQueue.push(v);

    while (!myQueue.empty()) {
        int now = myQueue.front();
        myQueue.pop();
        cout << now << ' ';

        for (int i : A[now]) {
            if (!visited[i]) {
                visited[i] = true;
                myQueue.push(i);
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        sort(A[i].begin(), A[i].end());
    }

    visited = vector<bool>(N + 1, false);
    DFS(V);
    cout << '\n';
    fill(visited.begin(), visited.end(), false);//방문 배열 초기화
    BFS(V);
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    read_data();
    solve();
}