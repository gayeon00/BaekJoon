#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	int cnt = 0;
	for (int k = 0; k < N; k++) {
		int target = A[k];
		int i = 0;
		int j = N - 1;

		while (i < j) {
			if (A[i] + A[j] == target) {
				if (i != k && j != k) {
					cnt++;
					break;
				} else if (i == k) {
					i++;
				} else if (j == k) {
					j--;
				}
			} else if (A[i] + A[j] < target) {
				i++;
			} else {
				j--;
			}
		}
	}

	cout << cnt;
}