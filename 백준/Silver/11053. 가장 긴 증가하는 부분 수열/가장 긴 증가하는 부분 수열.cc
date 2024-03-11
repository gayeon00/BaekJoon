// SUB11053.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int n;
int A[1001];
int D[1001] = { 0 };
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        int result = 0;
        for (int j = 1; j < i; j++) {
            if (A[j] < A[i]) {
                result = max(result, D[j]);
            }
        }
        D[i] = result + 1;
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        answer = max(answer, D[i]);
    }

    cout << answer;
}