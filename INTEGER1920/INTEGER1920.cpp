#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int target;
		cin >> target;
		int result = 0;

		int start = 0;
		int end = N - 1;

		while (start <= end) {
			//난 븅시니다....
			int mid = (start + end) / 2;
			int midv = A[mid];

			if (target > midv) {
				start = mid + 1;
			} else if (target < midv) {
				end = mid - 1;
			} else {
				result = 1;
				//ㄹㅇ 븅신이다;;;
				break;
			}
		}

		cout << result << '\n';
	}
}