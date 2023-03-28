#include <iostream>
#include <deque>

using namespace std;
typedef pair<int, int> Node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;

	deque<Node> myDeque = {};

	for (int i = 1; i <= N; i++) {
		int k;
		//숫자 입력 받기
		cin >> k;

		//덱이 비지 않고, 덱 마지막 숫자가 들어올 숫자보다 크면
		while (myDeque.size() && myDeque.back().second > k) {
			//덱 마지막 pop하기
			myDeque.pop_back();
		}

		//덱에 node(인덱스, 들어올 숫자) push하기
		myDeque.push_back(Node(i, k));
		//간격이 슬라이딩 윈도우보다 크면
		if (myDeque.back().first - myDeque.front().first >= L) {
			//맨 앞 pop하기
			myDeque.pop_front();
		}

		//결과적으로 맨 앞값이 최솟값이라 맨앞 출력하기
		cout << myDeque.front().second << ' ';
	}
}