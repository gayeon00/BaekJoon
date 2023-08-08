// NEARLYPRIME1456.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B;
    cin >> A >> B;

    long long b = sqrt(B);
    vector<bool> is_prime(b + 2, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i * i <= b; i++) {
        if (!is_prime[i]) {
            continue;
        }

        for (int j = i * i; j <= b; j += i) {
            is_prime[j] = false;
        }
    }

    int result = 0;
    for (int i = 2; i <= b; i++) {
        if (!is_prime[i]) {
            continue;
        }

        //2부터 루트B사이 소수들에 대해
        int n = 2;
        while (true) {
            if (pow(i, n) > B) break;

            if (A <= pow(i, n) && pow(i, n) <= B) {
                /*cout << i << ", " << n << '\n';
                cout << pow(i, n) << " is in between " << A << " and " << B << '\n';*/
                result++;
            }

            n++;
        }

    }

    cout << result;

    


}
