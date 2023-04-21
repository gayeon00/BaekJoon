#include <iostream>
using namespace std;

int N, Q;
long F[21], S[21];
bool visited[21] = { false };

int main() {
	cin >> N >> Q;
	F[0] = 1;
	for (int i = 1; i <= N; i++) {
		F[i] = F[i - 1] * i;
	}

	if (Q == 1) {
		long K;
		cin >> K;
		for (int i = 1; i <= N; i++) {
			for (int j = 1, cnt = 1; j <= N; j++) {
				if (visited[j]) continue;
				if (K <= cnt * F[N - i]) {
					K -= (cnt - 1) * F[N - i];
					visited[j] = true;
					S[i] = j;
					break;
				}
				cnt++;
			}
		}
		
		for (int i = 1; i <= N; i++) {
			cout << S[i] << ' ';
		}
	} else {
		long K = 1;
		for (int i = 1; i <= N; i++) {
			long cnt = 0;
			cin >> S[i];

			for (int j = 1; j < S[i]; j++) {
				if (!visited[j]) cnt++;
			}
			K += cnt * F[N - i];
			visited[S[i]] = true;
		}

		
		cout << K;
	}
}