// OKEUN17298.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;



int main() {
	int N;
	cin >> N;

	vector<int> A(N);
	vector<int> answer;
	for (int i = N-1; i >= 0; i--) {
		cin >> A[i];
	}

	stack<int> s;
	s.push(0);

	for (int i = 0; i < N; i++) {
		while (!s.empty() && s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			answer.push_back(-1);
		} else {
			answer.push_back(s.top());
		}

		s.push(A[i]);
	}

	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << " ";
	}
} 
