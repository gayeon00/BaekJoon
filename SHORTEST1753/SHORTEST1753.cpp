#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;
int V, E, K;

vector<vector<edge>> mlist;
vector<int> mdistance;

void read_data() {
	cin >> V >> E >> K;

	mlist.resize(V + 1);
	mdistance.resize(V + 1, INT_MAX);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		mlist[u].push_back({ v,w });
	}
}

void solve(int K) {
	priority_queue<edge, vector<edge>, greater<edge>> q;
	mdistance[K] = 0;
	q.push({ 0,K });

	while (!q.empty()) {
		edge curr = q.top();
		q.pop();

		for (auto i : mlist[curr.second]) {
			int next = i.first;
			int value = i.second;

			if (mdistance[next] > mdistance[curr.second] + value) {
				mdistance[next] = mdistance[curr.second] + value;
				q.push({ mdistance[next],next });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (mdistance[i] != INT_MAX) cout << mdistance[i] << '\n';
		else cout << "INF" << '\n';
	}

}
int main() {
	read_data();
	solve(K);
}