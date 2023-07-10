#include <iostream>
#include <vector>
using namespace std;

int result = 0;
vector<vector<int>> linked;
vector<bool> visited;

void DFS(int i) {
	visited[i] = true;

	for (auto j : linked[i]) {
		if(!visited[j]) DFS(j);
	}
}


int main() {
	int N, M;
	cin >> N >> M;

	linked.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		//연결 리스트에 넣기
		linked[u].push_back(v);
		linked[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			result++;
			DFS(i);
		}
	}
	cout << result;
}

