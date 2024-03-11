// SUMPRODUCT11049.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int n;
long D[502][502] = { 0 };
vector<pair<int, int>> M;

int execute(int s, int e) {
    int result = INT_MAX;
    //계산한 적 있는 범위라면 그 값 return
    if (D[s][e] != -1) {
        return D[s][e];
    }
    //행렬이 하나뿐이라면 연산 안해도 되니까 0 return
    if (s == e) {
        return 0;
    }
    //행렬이 두개 -> 행렬 곱셈 연산의 횟수
    if (s + 1 == e) {
        return M[s].first * M[s].second * M[e].second;
    }
    //행렬이 3개 이상일 경우 곱셈 연산 수
    for (int i = s; i < e; i++) {
        result = min(result, execute(s, i) + execute(i + 1, e) + M[s].first * M[i].second * M[e].second);
    }
    return D[s][e] = result;
}

int main() {
    cin >> n;
    M.resize(n + 1);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            D[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; i++) {
        int r, c;
        cin >> r >> c;
        M[i] = make_pair(r, c);
    }

    cout << execute(1, n);

}