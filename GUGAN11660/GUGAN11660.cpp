#include <iostream>
using namespace std;


int S[1025][1025] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;

			S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + tmp;
		}
	}

	for (int j = 0; j < M; j++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << S[x2][y2] - S[x2][y1 - 1] - S[x1 - 1][y2] + S[x1 - 1][y1 - 1] << '\n';
	}
}