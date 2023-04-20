#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> tree;
vector<int> depth;
int parent[21][100001];
vector<bool> visited;
int kmax;

void BFS(int node);
int executeLCA(int a, int b);

int main() {
	cin >> N;
	tree.resize(N + 1);

	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		tree[s].push_back(e);
		tree[e].push_back(s);
	}

	depth.resize(N + 1);
	visited.resize(N + 1);
	int tmp = 1;
	kmax = 0;

	while (tmp<=N) {
		tmp *= 2;
		kmax++;
	}

	BFS(1);
}

void BFS(int node) {
	queue<int> q;
	q.push(node);
	visited[node] = true;

	int level = 1; //초기 depth는 1(root니까)
	int now_size = 1; //현재 depth의 총 노드 수 초기값은 1(root니까)
	int cnt = 0; //현재 depth에서 탐색 완료한 노드의 수 

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int next : tree[curr]) {
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
			//next의 1번째 부모노드는 curr
			parent[0][next] = curr;
			//next의 깊이 저장
			depth[next] = level;
		}

		//현재 노드 탐색 완료했으니까 ++
		cnt++;
		if (cnt == now_size) { //현재 depth에 있는 모든 노드 탐색완료했다면
			cnt = 0; //다음 depth 탐색해야하니까 0으로 초기화
			now_size = q.size(); //다음 depth의 총 노드 개수는 큐에 들어가있는, 현재 depth의 노드들의 자식들
			level++; //다음 depth로 이동!
		}
	}
}