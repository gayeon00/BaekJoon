#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> A;

vector<bool> visited;

void DFS(int v) {
	if (visited[v]) {
		return;
	}

	visited[v] = true;

	//시작점에 딸린 놈들에 대해서 탐색 안한 놈이라면 탐색~~
	for (int i : A[v]) {
		if (!visited[i]) {
			DFS(i);
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	A.resize(N + 1);
	visited.resize(N + 1, false);

	for (int i = 1; i <= N; i++) {
		int u,v;
		cin >> u >> v;

		A[u].push_back(v);
		A[v].push_back(u);
	}

	int count = 0;

	for (int i = 1; i <= N; i++) {
		//시작점이 될 수 있다면 ++ => 새로운 묶음이 되는 거니까!
		if (!visited[i]) {
			count++;
			//시작점에 대해서 탐색
			DFS(i);
		}
	}

	cout << count;

}