// OKEUN17298.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;



//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int N;
//    vector<int> A;
//
//    cin >> N;
//    A.resize(N);
//    for (int i = N-1; i >= 0; i--) {
//        cin >> A[i];
//    }
//
//    stack<int> s;
//    vector<int> result;
//    for (int i = 0; i < N; i++) {
//        while (!s.empty() && s.top() <= A[i]) {
//            s.pop();
//        }
//        if (s.empty()) {
//            result.push_back(-1);
//        } else {
//            result.push_back(s.top());
//        }
//        s.push(A[i]);
//    }
//
//    for (int i = result.size() - 1; i >= 0; i--) {
//        cout << result[i] << ' ';
//    }
//}

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> result(N);

	stack<int> s;
	//처음 인덱스 그냥 집어너
	s.push(0);

	for (int i = 1; i < N; i++) {
		//스택이 비지 않고, 현재 수열A[i]이 스택의 top위치 값A[top]보다 큰 동안
		while (!s.empty() && A[i] > A[s.top()]) {
			result[s.top()] = A[i]; //top위치 값의 오큰수를 현재 수열 값으로 저장
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty()) {
		result[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << ' ';
	}

}
