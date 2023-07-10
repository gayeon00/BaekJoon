#include <iostream>
using namespace std;

int N;
int primes[4] = { 2,3,5,7 };
int result = 0;

bool is_prime(int num) {
	for (int i = 2; i < num / 2; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void prime(int num, int cnt) {
	int odd[5] = { 1,3,5,7,9 };
	cnt++;

	if (!is_prime(num)) return;

	if (cnt == N) {
		cout << num << '\n';
		return;
	}

	for (int i = 0; i < 5; i++) {
		
		prime(num * 10 + odd[i], cnt);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < 4; i++) {
		prime(primes[i], 0);
	}
}