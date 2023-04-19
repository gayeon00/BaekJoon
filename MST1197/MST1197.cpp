#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct edge {
	int start, end;
	int cost;

	bool operator>(const edge& e) const {
		return cost > e.cost;
	}
};

int V, E;
priority_queue<edge, vector<edge>, greater<edge>> q;
vector<int> parents;

void read_data() {
	//엣지리스트 입력받기
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		edge e;
		cin >> e.start >> e.end >> e.cost;
		q.push(e);
	}

	parents.resize(V + 1);
	for (int i = 1; i <= V; i++) {
		parents[i] = i;
	}
}

int mfind(int a) {
	if (parents[a] == a) return a;
	else return parents[a] = mfind(parents[a]);
}

void munion(int a, int b) {
	a = mfind(a);
	b = mfind(b);

	if (a != b) {
		parents[b] = a;
	}
}

void solve() {
	int result = 0;
	int cnt = 0;

	while (cnt < V - 1) {
		edge top = q.top();
		q.pop();

		int start = top.start;
		int end = top.end;
		int cost = top.cost;

		if (mfind(start) != mfind(end)) {
			munion(start, end);
			result += cost;
			cnt++;
		}
	}

	cout << result;
}


int main() {
	read_data();
	solve();
}