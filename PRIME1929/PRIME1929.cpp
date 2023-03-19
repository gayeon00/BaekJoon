// PRIME1929.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

void prime(int M, int N) {
    vector<bool> is_prime(N+1, true);

    is_prime[0] = false; is_prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = M; i <= N; i++) {
        if (is_prime[i]) cout << i << '\n';
    }
}

int main(){
    int M, N;
    cin >> M >> N;
    prime(M, N);
}