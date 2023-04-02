#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> edge;
static int V, E, K;
static vector<vector<edge>> mlist; //인접리스트
static vector<bool> visited;       //방문여부저장
static vector<int> mdistance;      //노드까지 최단거리
static priority_queue<edge, vector<edge>, greater<edge>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> K;
	mlist.resize(V + 1);
	visited.resize(V + 1);
	fill(visited.begin(), visited.end(), false);
	mdistance.resize(V + 1);
	fill(mdistance.begin(), mdistance.end(), 3000000);

	//인접리스트에 에지 정보 저장
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		mlist[u].push_back({ v,w });
	}

	//큐에 출발 노드 넣기{거리, 노드} -> 거리순으로 정렬돼야하니까
	q.push({ 0,K });
	mdistance[K] = 0;

	while (!q.empty()) {
		edge now = q.top();
		q.pop();
		int now_n = now.second;
		int now_v = now.first;

		if (visited[now_n]) continue; //이미 방문한 노드는 스킵
		visited[now_n] = true;
		for (int i = 0; i < mlist[now_n].size(); i++) { //노드의 인접 노드들에 대해
			edge next = mlist[now_n][i];
			int node = next.first;
			int value = next.second;

			if (mdistance[now_n] + value < mdistance[node]) {
				mdistance[node] = mdistance[now_n] + value;
				q.push({ mdistance[node] , node });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (visited[i]) cout << mdistance[i] << '\n';
		else			cout << "INF" << '\n';
	}
}

