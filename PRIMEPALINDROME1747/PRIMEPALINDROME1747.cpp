// PRIMEPALINDROME1747.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_palindrome(int i) {
	string str = to_string(i);
	int start = 0, end = str.size() - 1;
	while (start < end) {
		if (str[start] != str[end]) return false;
		start++;
		end--;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long N;
	cin >> N;

	vector<bool> is_prime(10000001, true);
	is_prime[0] = false;
	is_prime[1] = false;
	
	
	for (int i = 2; i * i <= 10000000; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= 10000000; j += i) {
				is_prime[j] = false;
			}
		}
	}

	//is_prime[i]가 true인 i가 소수
	for (int i = N; i <= 10000000; i++) {
		if (is_prime[i] && is_palindrome(i)) {
			cout << i;
			break;
		}
	}
}
