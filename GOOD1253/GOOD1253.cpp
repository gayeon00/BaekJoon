// GOOD1253.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, cnt=0;
vector<int> A;

void read_data() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
}

void solve() {
    sort(A.begin(), A.end());
    
    for (int k = 0; k < N; k++) {
        int find = A[k];
        int i = 0;
        int j = N - 1;

        while (i < j) {
            if (A[i] + A[j] == find) {
                if (i != k && j != k) {
                    cnt++;
                    break;
                } else if (i == k) {
                    i++;
                } else if (j == k) {
                    j--;
                }
            } else if (A[i] + A[j] > find) {
                j--;
            } else {
                i++;
            }
        }
    }
}

void print_data() {
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    read_data();
    solve();
    print_data();
}
