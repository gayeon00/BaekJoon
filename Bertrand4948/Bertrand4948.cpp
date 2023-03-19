// Bertrand4948.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

vector<bool> is_prime(300000, true);

void prime(int n) {
    is_prime[0] = false; is_prime[1] = false;
    for (long long i = 2; i * i <= n; i++) { //i*i부터 볼꺼니까 얘가 n보다 작아야 효용이 있지. 
        if (is_prime[i]) {
            for (long long j = i * i; j <= n; j += i) {
                //i*i부터 하는 이유는, i보다 작은 아이들(k)은 이미 처리됐고,
              // 그 아이들에 의해 i*i전까지(i*k로) 다 처리됨! 그러니까 i*i부터만 보면 됨!
                //ex) 5를 볼 경우, 2,3,4는 다 처리됐으니까 적어도 5*4까진 다 처리됨! 그러니까 5*5부터 보면 됨
                is_prime[j] = false;
            }
        }
    }
    //for (auto i : is_prime) {
    //    cout << i << ' ';
    //}
}

int main() {
    int n;
    vector<int> numbers;
    while (true) {
        cin >> n;
        if (n == 0) break;
        numbers.push_back(n);
    }

    prime(123456*2);

    for (auto i : numbers) {
        int count = 0;
        for (int j = i+1; j <= 2 * i; j++) {
            if (is_prime[j]) count++;
        }
        cout << count << '\n';
    }
}
