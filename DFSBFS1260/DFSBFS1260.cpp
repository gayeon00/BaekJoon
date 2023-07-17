#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, V;
vector<vector<int>> A;
vector<bool> visited;
queue<int> q;

void DFS(int v, vector<bool>& visited) {
	visited[v] = true;
	cout << v << " ";

	for (auto next : A[v]) {
		if (!visited[next]) {
			DFS(next, visited);
		}
	}

	return;
}

void BFS(int v, vector<bool>& visited) {
	q.push(v);

	while (!q.empty()) {
		int now = q.front();

		if (!visited[now]) {
			visited[now] = true;
			cout << now << " ";
			for (auto next : A[now]) {
				if (!visited[next]) {
					q.push(next);
				}
			}
		}
		q.pop();
	}

}

int main() {
	cin >> N >> M >> V;

	A.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		A[u].push_back(v);
		A[v].push_back(u);
	}

	// 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하기 위해 정렬
	for (int i = 1; i <= N; i++) {
		sort(A[i].begin(), A[i].end());
	}

	DFS(V, visited);
	cout << '\n';
	visited.clear();
	visited.resize(N + 1, false);
	BFS(V, visited);
}