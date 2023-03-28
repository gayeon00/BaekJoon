#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, count = 0;
	vector<int> A;

	cin >> N;
	//일단 숫자 배열 입력 받기
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}

	//숫자 배열 정렬하기
	sort(A.begin(), A.end());

	//k마다 좋은 수 찾기
	for (int i = 0; i < N; i++) {
		int start = 0; int end = N - 1;
		while (start < end) {
			if (A[start] + A[end] == A[i]) {
				if (start != i && end != i) {
					count++;
					break;
				} else if (start == i) {
					start++;
				} else if (end == i) {
					end--;
				}
			} else if (A[start] + A[end] > A[i]) {
				end--;
			} else {
				start++;
			}
		}
	}

	cout << count << '\n';
	return 0;
}