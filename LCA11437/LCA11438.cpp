#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N, M;
vector<vector<int>> tree;
vector<int> depth;
int kmax;
int parent[21][100001];
vector<bool> visited;

int executeLCA(int a, int b);
void BFS(int node);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	tree.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
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

	for (int k = 1; k <= kmax; k++) {
		for (int n = 1; n <= N; n++) {
			parent[k][n] = parent[k - 1][parent[k - 1][n]];
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		int LCA = executeLCA(a, b);
		cout << LCA << '\n';
	}
}

int executeLCA(int a, int b) {
	if (depth[a] > depth[b]) {
		swap(a, b);
	}

	for (int k = kmax; k >= 0; k--) {
		if (pow(2, k) <= depth[b] - depth[a]) {
			if (depth[a] <= depth[parent[k][b]]) {
				b = parent[k][b];
			}
		}
	}

	for (int k = kmax; k >= 0 && a != b; k--) {
		if (parent[k][a] != parent[k][b]) {
			a = parent[k][a];
			b = parent[k][b];
		}
	}

	int LCA = a;

	if (a != b) {
		LCA = parent[0][LCA];
	}

	return LCA;
}

void BFS(int node) {
	queue<int> q;
	q.push(node);
	visited[node] = true;

	int level = 1;
	int now_size = 1;
	int cnt = 0;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int next : tree[curr]) {
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
			depth[next] = level;
			parent[0][next] = curr;
		}
		cnt++;

		if (cnt == now_size) {
			cnt = 0;
			now_size = q.size();
			level++;
		}
	}
}