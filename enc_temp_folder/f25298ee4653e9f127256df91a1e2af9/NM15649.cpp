#include <iostream>
#include <queue>

using namespace std;

int N, M;
bool visited[9] = { false };
void DFS(int i, int count) {
	visited[i] = true;
	
	if (count == M) {
		cout << '\n';
		return;
	}

	for (int j = i + 1; j <= N; j++) {
		if (visited[j]) continue;

		cout << i << " ";
		DFS(j, count + 1);
	}

	visited[i] = false;
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		DFS(i, 1);
	}
}