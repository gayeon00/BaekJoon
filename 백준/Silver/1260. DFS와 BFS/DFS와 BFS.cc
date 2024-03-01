#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector< vector<int>> L;
vector<bool> visited;


void DFS(int node) {
	cout << node << ' ';
	visited[node] = true;

	for (int i : L[node]) {
		if (!visited[i]) {
			DFS(i);
		}
	}
}

void BFS(int node) {
	queue<int> myQueue;
	myQueue.push(node);
	visited[node] = true;

	while (!myQueue.empty()) {
		int now_node = myQueue.front();
		myQueue.pop();
		cout << now_node << " ";
		for (int i : L[now_node]) {
			if (!visited[i]) {
				myQueue.push(i);
				visited[i] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;

	L.resize(N + 1);
	//인접 리스트 만들기
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		L[u].push_back(v);
		L[v].push_back(u);
	}

	//정렬
	for (int i = 1; i <= N; i++) {
		sort(L[i].begin(), L[i].end());
	}

	visited = vector<bool>(N + 1, false);
	DFS(V);
	cout << '\n';
	fill(visited.begin(), visited.end(), false);
	BFS(V);

}