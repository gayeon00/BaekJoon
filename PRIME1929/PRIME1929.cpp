#include <iostream>
#include <vector>
using namespace std;

int main() {

	int M, N;
	cin >> M >> N;

	vector<bool> is_prime(N + 1, true);
	is_prime[1] = false;
	for (int i = 2; i * i <= N; i++) {
		for (int j = i * i; j <= N; j+=i) {
			if (is_prime[i]) {
				/*cout << i << "is prime number" << '\n';
				cout << "so " << j << " can't be prime number" << '\n';*/
				is_prime[j] = false;
			}

		}
	}

	for (int i = M; i <= N; i++) {
		if (is_prime[i]) cout << i << '\n';
	}
}