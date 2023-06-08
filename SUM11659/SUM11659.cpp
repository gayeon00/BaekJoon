#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S[100001];

	int N, M;
	cin >> N >> M;

	S[0] = 0;
	/*S[i,j] = S[i] - S[j-1]*/
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		S[i] = S[i - 1] + tmp;
	}

	for (int k = 0; k < M; k++) {
		int i, j;
		cin >> i >> j;
		cout << S[j] - S[i - 1] << '\n';
	}
}