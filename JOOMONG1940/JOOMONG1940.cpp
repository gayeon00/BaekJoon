// JOOMONG1940.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int start_index = 0, end_index = N - 1;
    int count = 0;

    while (start_index < end_index) {
        int sum = v[start_index] + v[end_index];
        if (sum == M) {
            count++;
            start_index++;
            end_index--;
        } else if (sum < M) {
            start_index++;
        } else {
            end_index--;
        }
    }

    cout << count;
}
