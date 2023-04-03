#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> node;

static int N, M, K;
static int W[1001][1001];
static priority_queue<int> distQueue[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		W[a][b] = c;
	}

	priority_queue < node, vector<node>, greater<node>> pq;
	pq.push({ 0,1 });
	distQueue[1].push(0);

	while (!pq.empty()) {
		node u = pq.top();
		pq.pop();

		for (int adjNode = 1; adjNode <= N; adjNode++) {
			if (W[u.second][adjNode]!=0) { //현재 노드와 타켓 노드사이 거리
				if (distQueue[adjNode].size() < K) {
					pq.push({ u.first + W[u.second][adjNode] , adjNode });
					distQueue[adjNode].push(u.first + W[u.second][adjNode]);
				} else if(distQueue[adjNode].top() > u.first + W[u.second][adjNode]) {
					distQueue[adjNode].pop();
					pq.push({ u.first + W[u.second][adjNode] , adjNode });
					distQueue[adjNode].push(u.first + W[u.second][adjNode]);
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (distQueue[i].size() == K) {
			cout << distQueue[i].top() << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
}