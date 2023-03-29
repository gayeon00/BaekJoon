#include <iostream>
#include <vector>

using namespace std;

const int N = 1000000;

int main() {

	int m, n;
	cin >> m >> n;

	vector<bool> is_prime(N + 1, true);

	is_prime[0] = false; is_prime[1] = false;

	for (int i = 2; i * i <= n; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}

	for (int i = m; i <= n; i++) {
		if (is_prime[i]) cout << i << '\n';
	}

}