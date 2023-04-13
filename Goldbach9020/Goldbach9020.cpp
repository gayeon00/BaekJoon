#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

vector<int> primes(int n) {
	bool is_prime[10001] = { true };
	memset(is_prime, true, 10001);
	is_prime[0] = false, is_prime[1] = false;

	for (int i = 2; i * i <= n; i++) {
		if (!is_prime[i]) continue;
		
		for (int j = i * i; j <= n; j+=i) {
			is_prime[j] = false;
		}
	}

	vector<int> primes_list;
	for (int i = 0; i <= n; i++) {
		if (is_prime[i]) primes_list.push_back(i);
	}
	return primes_list;
}

void getTwoNumbers(int n, vector<int>& prime_list) {
	int min = 10001;
	int minI = 0, minJ = 0;
	for (auto i : prime_list) {
		for (auto j : prime_list) {
			if (i + j == n && abs(i - j) < min) {
				min = abs(i - j);
				minI = i, minJ = j;
			}
		}
	}
	cout << minI << " " << minJ << '\n';
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		vector<int> prime_list = primes(n);
		getTwoNumbers(n, prime_list);
	}
}