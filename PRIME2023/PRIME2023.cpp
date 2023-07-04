// PRIME2023.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

void DFS(int prime, int jarisu);

static int N;
vector<int> result;
int main() {
    cin >> N;

    int primes[4] = { 2,3,5,7 };
    for (auto prime : primes) {
        DFS(prime, 1);
    }
}

bool isPrime(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void DFS(int number, int jarisu) {
    if (jarisu == N) {
        if (isPrime(number)) {
            cout << number << '\n';
        }
        return;
    }

    int primes[5] = { 1,3,5,7,9 };
    for (int a : primes) {
        if (isPrime(number * 10 + a)) {
            DFS(number * 10 + a, jarisu + 1);
        }
    }
}
