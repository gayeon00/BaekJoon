#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, L;
deque<pair<int, int>> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;

	int tmp;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;

		if (q.size() == 0) {
			q.push_back({i,tmp});
		} else {
			if (i - q.front().first >= L) {
				q.pop_front();
			}
			while (q.size() != 0 && q.back().second > tmp) {
				q.pop_back();
			}
			q.push_back({ i,tmp });
		}

		cout << q.front().second << " ";
	}
}