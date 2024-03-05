#include <iostream>
#include <vector>

using namespace std;

int n, q;
//각 자릿수에서 만들 수 있는 경우의 수 (팩토리얼)
long F[21];
long S[21];
bool visited[21] = { false };

int main() {	
	cin >> n >> q;
	F[0] = 1;

	for (int i = 1; i <= n; i++) {
		F[i] = F[i - 1] * i;
	}

	if (q == 1) {
		long k;
		cin >> k;

		for (int i = 1; i <= n; i++) {
			for (int j = 1, cnt = 1; j <= n; j++) {
				if (visited[j]) {
					continue;
				}

				if (k <= cnt * F[n - i]) {
					S[i] = j;
					k -= F[n - i] * (cnt - 1);
					visited[j] = true;
					break;
				}

				cnt++;
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << S[i] << ' ';
		}
	} else if (q == 2) {
		long k = 1;

		for (int i = 1; i <= n; i++) {
			cin >> S[i];
			long cnt = 0;

			for (int j = 1; j < S[i]; j++) {
				if (!visited[j]) {
					cnt++;
				}
			}

			k += cnt * F[n - i];
			visited[S[i]] = true;
		}
		cout << k << '\n';
	}


}