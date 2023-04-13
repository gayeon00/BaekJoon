#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[9];
bool visited[9];

void DFS(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;

		arr[k] = i;
		visited[i] = true;
		DFS(k + 1);
		visited[i] = false;
	}
}


int main() {
	cin >> N >> M;

	DFS(0);
}