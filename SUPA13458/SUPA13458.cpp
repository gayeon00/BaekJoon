// SUPA13458.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> As;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        As.push_back(a);
    }

    int B, C;
    cin >> B >> C;

    long long sum = 0;
    for (int a: As) {
        a -= B;
        if (a <= 0) {
            sum++;
        } else {
            sum++;
            if (a % C == 0) {
                sum += a / C;
            } else {
                sum += (a / C) + 1;
            }
        }
    }
    cout << sum;
}
