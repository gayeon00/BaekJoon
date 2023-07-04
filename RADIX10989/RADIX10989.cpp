#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int A[10001] = { 0 };
	int tmp;

	for (int i = 1; i <= N; i++) {
		cin >> tmp;

		A[tmp]++;
	}

	for (int i = 0; i <= 10000; i++) {
		if (A[i] != 0) {
			for (int j = 0; j < A[i]; j++) {
				cout << i << '\n';
			}
		}
	}
}