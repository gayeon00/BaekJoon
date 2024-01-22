#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

struct compare {
	bool operator()(int& l, int& r) {
		if (abs(l) == abs(r)) {
			return l > r;
		}
		return abs(l) > abs(r);
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, compare> pq;
	for (int i = 0; i < N; i++) {
		int op;
		cin >> op;
		if (op==0) {
			//배열에서 절댓값이 가장 작은 값 출력하고 그 값 pop;
			if (pq.empty()) {
				cout << "0" << '\n';
			} else {
				cout << pq.top() << '\n';
				pq.pop();
			}
			
		} else {
			//배열에 넣기
			pq.push(op);
		}
	}

	return 0;
}