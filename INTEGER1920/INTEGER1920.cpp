// INTEGER1920.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

//A에서 이진탐색으로 number찾기
void binary(const int number, const vector<int>& A) {
    int start = 0; int end = N - 1;
    bool find = false;
    while (start <= end) {
        int mindex = (start + end) / 2;
        int mnumber = A[mindex];

        if (mnumber > number) {
            end = mindex - 1;
        } else if (mnumber < number) {
            start = mindex + 1;
        } else {
            //찾았을 경우
            find = true;
            break;
        }
    }
    
    if (find) cout << 1 << '\n';
    else cout << 0 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N;
    vector<int> A;

    //N개로 이루어진 숫자 배열 A입력받기
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    //이진 탐색 위해 정렬하기
    sort(A.begin(), A.end());

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int number;
        cin >> number;

        binary(number, A);
    }
}