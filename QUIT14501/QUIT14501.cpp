#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int D[15]{ 0 };
	int T[15]{ 0 };
	int P[15]{ 0 };

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = N; i > 0; i--) {
		if (i + T[i] > N + 1) {
			D[i] = D[i + 1];
		} else {
			D[i] = max(D[i + 1], D[i + T[i]] + P[i]);
		}
	}

	cout << D[1];
}