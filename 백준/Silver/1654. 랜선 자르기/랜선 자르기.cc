// LAN1654.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    vector<long long> lans(k, 0);
    long long start = 1, end = 0;
    for (int i = 0; i < k; i++) {
        cin >> lans[i];
        end = max(end, lans[i]);
    }
    long long answer = 0;
    while (start <= end) {
        //mid가 랜선의 길이
        long long mid = (start + end) / 2;
        int result = 0;
        for (int i = 0; i < k; i++) {
            //i번째 랜선으로 만들 수 있는 랜선의 갯수
            result += (lans[i] / mid);
        }

        //mid길이의 랜선을 n보다 많이, 충분히 만들 수 있다면 mid보다 큰 얘들도 충분히 만들 수 있는지 봐야지
        if (result >= n) {
            start = mid + 1;
            answer = mid;
        } else {
            end = mid - 1;
        }
    }

    cout << answer;

    return 0;
}
