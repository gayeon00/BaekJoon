// ABCDE13023.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> A;

int result = -1;

void DFS(int now, int depth, vector<bool> visited) {
    visited[now] = true;

    if (depth == 5) {
        result = 1;
        return;
    }

    for (auto next : A[now]) {
        if (!visited[next] && result != 1) {
            DFS(next, depth + 1, visited);
        }
    }

}

int main() {
    cin >> N >> M;
    A.resize(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        A[u].push_back(v);
        A[v].push_back(u);
    }

    for (int i = 0; i < N; i++) {
        vector<bool> visited(N, false);
        DFS(i, 1, visited);

        if (result == 1) {
            cout << 1;
            return 0;
        }
    }

    cout << 0;
    return 0;
}
