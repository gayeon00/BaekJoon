// TREE1167.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int > pii;

int V;
long long result = 0;
vector<vector<pii>> A;

void read_data();
void solve();
int BFS(int v);

int main() {
    read_data();
    solve();
}

void read_data() {
    cin >> V;
    A.resize(V + 1);

    for (int i = 0; i < V; i++) {
        int v;
        cin >> v;

        int tmp;
        int idx = 1;
        while (true) {
            cin >> tmp;

            if (tmp == -1) {
                break;
            }

            if (idx % 2 == 1) {
                //노드
                A[v].push_back({ tmp,0 });
            } else {
                //거리
                A[v].back().second = tmp;
            }

            idx++;
        }
    }
}

void solve() {
    int node1 = BFS(1);
    BFS(node1);

    cout << result;
}

int max_idx(vector<long long>& distance) {
    long long myMax = 0;
    int myMaxIndex = 0;

    for (int i = 1; i < V + 1; i++) {
        if (distance[i] > myMax) {
            myMax = distance[i];
            myMaxIndex = i;
        }
    }

    result = myMax;
    return myMaxIndex;
}

int BFS(int v) {
    //방문 여부 기록
    vector<bool> visited(V + 1, false);
    // 임의의 점 에서, 정점 1번부터 V번까지의 거리
    vector<long long> distance(V + 1, 0);

    queue<int> q;
    q.push(v);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        visited[v] = true;

        for (auto next : A[now]) {
            int nv = next.first;
            int nw = next.second;

            if (!visited[nv]) {
                q.push(nv);
                visited[nv] = true;
                distance[nv] = distance[now] + nw;
            }
        }
    }

    return max_idx(distance);
}


