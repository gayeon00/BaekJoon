#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, L;
deque<pair<int, int>> q;
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		
		//값이 들어올 때마다 덱에서 들어오는 값보다 큰 수를 뺌
		while (!q.empty() && q.back().first > tmp) {
			q.pop_back();
		}

		q.push_back({ tmp, i });

		//범위에서 벗어난 노드는 제거
		if (q.front().second <= i - L) {
			q.pop_front();
		}

		cout << q.front().first << " ";
	}


}