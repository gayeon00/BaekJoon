// SUM11659.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int S[100001] = {};

    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        S[i] = S[i - 1] + tmp;
    }

    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        cout << S[end] - S[start - 1] << '\n';
    }
}