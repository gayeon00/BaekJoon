// SORT2750.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (A[j+1] < A[j]) {
                int tmp = A[j + 1];
                A[j + 1] = A[j];
                A[j] = tmp;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << '\n';
    }
}
