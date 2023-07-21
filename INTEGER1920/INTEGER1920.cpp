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
		bool flag = false;
		int x;
		cin >> x;

		int start = 0, end = A.size() - 1;

		while (start <= end) {
			int med = (start + end) / 2;

			if (x < A[med]) {
				end = med - 1;
			} else if (x > A[med]) {
				start = med + 1;
			} else {
				flag = true;
				break;
			}
		}
		
		if (flag) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

}