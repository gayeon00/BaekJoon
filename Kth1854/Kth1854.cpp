#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> edge;
int n, m, k;
//top(젤 큰놈)이랑 들어오는 얘랑 비교해서 들어오는 얘가 더 작으면 top 꺼내버리고 들어오는 얘 넣기
vector<vector<edge>> mlist;
vector<priority_queue<int>> mdistance;

void read_data() {
	cin >> n >> m >> k;
	
	mlist.resize(n + 1);
	mdistance.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		mlist[a].push_back({ b,c });
	}
}

void solve(int start) {
	priority_queue<edge, vector<edge>, greater<edge>> q;

	q.push({ 0,1 });
	mdistance[1].push(0);

	while (!q.empty()) {
		edge curr = q.top();
		q.pop();

		for (auto i : mlist[curr.second]) {
			int next = i.first;
			int value = i.second;

			//우선순위 큐 배열이 다 채워지지 않았을 경우
			if (mdistance[next].size() < k) {
				mdistance[next].push({ curr.first + value });
				q.push({ curr.first + value, next });
			}
			//우선순위 큐 배열이 k개로 다 채워졌을 경우
			else if (mdistance[next].top() > curr.first + value) {
				mdistance[next].pop();
				mdistance[next].push({ curr.first + value });
				q.push({ curr.first + value, next });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (mdistance[i].size() == k) cout << mdistance[i].top() << '\n';
		else cout << -1 << '\n';
	}
}

int main() {
	read_data();
	solve(1);
}