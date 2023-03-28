
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	int A[100001] = {};

	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		A[i] = A[i - 1] + tmp;
	}


	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		cout << A[v] - A[u - 1] << '\n';
	}
}