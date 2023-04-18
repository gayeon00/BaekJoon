#include <iostream>
#include <tuple>
#include <vector>
#include <limits.h>

using namespace std;
typedef tuple<int, int, int> edge;

int N, M;
vector<edge> edges;
//거리 ~10000, 노선 개수 6000이니까 long으로!
vector<long> mdistance;

void read_data() {
	cin >> N >> M;

	mdistance.resize(N + 1, LONG_MAX);

	for (int i = 0; i < M; i++) {
		int start, end, time;
		cin >> start >> end >> time;
		edges.push_back(make_tuple(start, end, time));
	}
}

void solve() {
	mdistance[1] = 0;

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			edge curr = edges[j];
			int start = get<0>(curr);
			int end = get<1>(curr);
			int time = get<2>(curr);

			if (mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + time) {
				mdistance[end] = mdistance[start] + time;
			}
		}
	}

	bool flag = true;

	for (int j = 0; j < M; j++) {
		edge curr = edges[j];
		int start = get<0>(curr);
		int end = get<1>(curr);
		int time = get<2>(curr);

		if (mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + time) {
			flag = false;
			break;
		}
	}
	
	if (flag) {
		for (int i = 2; i <= N; i++) {
			if (mdistance[i] != LONG_MAX) cout << mdistance[i] << '\n';
			else cout << -1 << '\n';
		}
	} else {
		cout << -1 << '\n';
	}
}

int main() {
	read_data();
	solve();
	return 0;
}