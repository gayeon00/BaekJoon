// SHORTEST1753.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pii>> A(V+1);
    vector<bool> visited(V+1, false);

    //인접리스트 입력받기
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back({ v,w });
    }

    //최단거리 배열 초기화
    vector<int> result(V + 1, 3000000);
    result[K] = 0;
    //큐
    priority_queue<pii, vector<pii>, greater<pii>> myQueue;
    myQueue.push({0,K});

    while (!myQueue.empty()) {
        //최단거리 노드 선택
        pii now = myQueue.top();
        myQueue.pop();
        int now_v = now.second;
        //방문한 적 있는지 확인
        if (visited[now_v]) {
            continue;
        }

        //방문했다고 업데이트
        visited[now_v] = true;

        for (int i = 0; i < A[now_v].size(); i++) {
            pii tmp = A[now_v][i];
            int next = tmp.first;
            int value = tmp.second;

            if (result[next] > result[now_v] + value) {
                result[next] = result[now_v] + value;
                myQueue.push({ result[next], next });
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (visited[i]) cout << result[i] << '\n';
        else cout << "INF" << '\n';
    }


}
