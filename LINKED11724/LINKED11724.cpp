#include <iostream>
#include <vector>

using namespace std;

vector < vector<int>> L;
vector<bool> visited;

void DFS(int node) {
	if (visited[node]) return;
	visited[node] = true;
	for (int i : L[node]) {
		if (!visited[i]) DFS(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	L.resize(N + 1);

	//링크드 리스트로 그래프 입력받기
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		L[u].push_back(v);
		L[v].push_back(u);
	}

	int cnt = 0;

	visited.resize(N + 1, false);
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			DFS(i);
			cnt++;
		}
	}

	cout << cnt << '\n';
}