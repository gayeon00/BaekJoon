#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> A(N + 1);
	vector<int> indegree(N + 1);
	vector<int> selfBuild(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> selfBuild[i];

		while (true) {
			int tmp;
			cin >> tmp;
			if (tmp == -1) break;
			
			indegree[i]++;
			A[tmp].push_back(i);
		}
	}

	queue<int> myQueue;
	vector<int> result(N + 1);

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) myQueue.push(i);
	}

	while (!myQueue.empty()) {
		int now = myQueue.front();
		myQueue.pop();
		for (int next : A[now]) {
			indegree[next]--;
			result[next] = max(result[next], result[now] + selfBuild[now]);
			if (indegree[next] == 0) {
				myQueue.push(next);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << result[i] + selfBuild[i] << '\n';
	}
	
}