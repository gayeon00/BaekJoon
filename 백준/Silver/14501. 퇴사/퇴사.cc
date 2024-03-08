#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int T[21];
	int P[21];
	int S[21] = { 0 };

	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = n; i >= 1; i--) {
		if (i + T[i] <= n + 1) {
			S[i] = max(P[i] + S[i + T[i]], S[i + 1]);
		} else {
			S[i] = S[i + 1];
		}
	}

	cout << S[1];
}