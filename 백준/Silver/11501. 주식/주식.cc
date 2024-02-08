// Stock11501.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> vec(n, 0);

        for (int j = 0; j < n; j++) {
            cin >> vec[j];
        }

        long long answer = 0;
        int max_value = -1;

        for (int j = n - 1; j >= 0; j--) {
            max_value = max(max_value, vec[j]);
            answer += max_value - vec[j];
        }
        cout << answer << '\n';
        
    }
}
