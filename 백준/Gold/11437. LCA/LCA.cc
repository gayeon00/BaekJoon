// LCA11437.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//인접리스트로 트리 데이터 구현
vector<vector<int>> mlist;
//bfs에 활용할 방문 여부 체크용
vector<bool> visited;
vector<int> depth;
vector<int> parent;

void bfs(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    int level = 1;     //노드의 깊이
    int now_size = 1;  //현재 레벨에 있는 노드 수 추적
    int count = 0;     //count가 now_size에 도달하면 현재 레벨의 모든 노드가 방문됐음을 의미, 다음 레벨로 이동하기

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next : mlist[now]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                parent[next] = now; //부모 노드 저장
                depth[next] = level;//노드 깊이 저장
            }
        }

        count++;
        if (count == now_size) {
            count = 0;
            now_size = q.size(); //q에 들어있는게 다음 레벨에 있는 노드들이기 때문에 이렇게 함으로써 다음 레벨에 있는 노드 수를 지정해준다. 
            level++;
        }
    }
}

void lca(int a, int b) {
    //a가 depth가 더 크도록 맞추기
    if (depth[a] < depth[b]) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    //두 노드 깊이 맞추기
    while (depth[a] != depth[b]) {
        a = parent[a];
    }

    //같은 조상이 나올 때 까지 한칸 씩 올라가기
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }

    cout << a << '\n';


}

int main() {
    int n;
    cin >> n;

    //인접리스트로 트리 데이터 구현
    mlist.resize(n + 1);
    visited.resize(n + 1);
    depth.resize(n + 1);
    parent.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        mlist[u].push_back(v);
        mlist[v].push_back(u);
    }

    //bfs이용하여 깊이, 부모 구하기
    bfs(1);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        lca(u, v);
    }
    
}
