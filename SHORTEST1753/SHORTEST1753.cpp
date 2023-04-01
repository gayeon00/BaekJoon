#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E, K;
typedef pair<int, int> node;

static vector<vector<node>> mlist;
static vector<int> mdistance;
static vector<bool> visited;
static priority_queue<node, vector<node>, greater<node>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	cin >> V >> E >> K;

	mlist.resize(V + 1);
	mdistance.resize(V + 1);
	fill(mdistance.begin(), mdistance.end(), 3000000);
	visited.resize(V + 1);
	fill(visited.begin(), visited.end(), false);


	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		mlist[u].push_back(make_pair(v, w));
	}

	q.push(make_pair(0, K));
	mdistance[K] = 0;

	while (!q.empty()) {
		node now = q.top();
		q.pop();
		int n_v = now.second;
		int n_w = now.first;
		if (visited[n_v]) continue;
		visited[n_v] = true;

		for (int i = 0; i < mlist[n_v].size(); i++) {
			node tmp = mlist[n_v][i];
			int next = tmp.first;
			int value = tmp.second;

			if (!visited[next] && (mdistance[n_v]+value < mdistance[next])) {
				mdistance[next] = mdistance[n_v] + value;
				q.push(make_pair(mdistance[next], next));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (visited[i]) {
			cout << mdistance[i] << '\n';
		} else {
			cout << "INF" << '\n';
		}
	}
}