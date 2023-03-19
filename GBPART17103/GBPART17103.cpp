// GBPART17103.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

vector<bool> is_prime(1000001,true);
//vector<int> prime_list;
int T;
vector<int> Ns;

void prime() {
    is_prime[0] = false; is_prime[1] = false;
    for (int i = 2; i * i <= 1000000; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                is_prime[j] = false;
            }
        }
    }

    //for (int i = 0; i < is_prime.size();i++) {
    //    if (is_prime[i]) prime_list.push_back(i);
    //}
}

void read_data() {
    cin >> T;
    int tmp;
    for (int i = 0; i < T; i++) {
        cin >> tmp;
        Ns.push_back(tmp);
    }
}

void solve() {
    for (auto n : Ns) {
        int count = 0;
        for (int i = 0; i <= n/2; i++) {
            if (is_prime[i] && is_prime[n - i]) count++;
        }
        cout << count << '\n';
    }
}

int main(){
    read_data();
    prime();
    solve();

}
