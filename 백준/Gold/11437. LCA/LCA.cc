#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> mlist;
vector<bool> visited;
vector<int> depth;
vector<int> parent;

void bfs(int node) {
	queue<int> q;
	q.push(node);
	visited[node] = true;
	int count = 0;
	int now_size = 1;
	int level = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : mlist[now]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				parent[next] = now;
				depth[next] = level;
			}
		}

		count++;

		if (count == now_size) {
			count = 0;
			now_size = q.size();
			level++;
		}
	}
}

void lca(int a, int b) {
	//a가 더 깊도록
	if (depth[a] < depth[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	//a를 b까지 끌어올리기
	while (depth[a] != depth[b]) {
		a = parent[a];
	}

	//a랑 b 만날 때 까지 동시에 끌어올리기
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	cout << a << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	mlist.resize(n + 1);
	visited.resize(n + 1);
	depth.resize(n + 1);
	parent.resize(n + 1);

	//인접리스트로 트리 완성하기
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;

		mlist[u].push_back(v);
		mlist[v].push_back(u);
	}

	//깊이랑 부모 노드 구하기
	bfs(1);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		lca(u, v);
	}
}