// Goldbach9020.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int N = 10000;

int T;
vector<int> targetNumbers;
vector<bool> is_prime(N + 1, true);

void read_data() {
    cin >> T;
    int tmp;
    for (int i = 0; i < T; i++) {
        cin >> tmp;
        targetNumbers.push_back(tmp);
    }
}

void primes(int n) {
    
    is_prime[0] = false, is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void isGoldBach(int n, vector< bool>& primes_list) {
    for (int i = 0; i < n / 2; i++) {
        if (primes_list[n / 2 - i] && primes_list[n / 2 + i]) {
            cout << (n / 2 - i) << " " << (n / 2 + i) << '\n';
            break;
        }
    }
}


void solve() {
    primes(N);
    for (auto i : targetNumbers) {
        isGoldBach(i, is_prime);
    }

}

int main() {
    read_data();
    solve();
    
    
}
