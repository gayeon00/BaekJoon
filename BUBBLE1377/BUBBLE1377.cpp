#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> A(N);

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;

		A[i] = { tmp, i };
	}

	sort(A.begin(), A.end());

	vector<int> result(N);
	int max = 0;
	for (int i = 0; i < N; i++) {
		if (A[i].second - i > max) {
			max = A[i].second - i;
		}
	}

	cout << max + 1;
}