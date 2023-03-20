// HANOI11729.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;
vector<pair<int,int>> arr;
int hanoi(int from, int to, int n) {
    if (n == 1) {
        arr.push_back({ from, to });
        return 1;
    }

    return hanoi(from, 6 - (from + to), n - 1) + hanoi(from, to, 1) + hanoi(6 - (from + to), to, n - 1);
}

int main(){
    int n;
    cin >> n;
    int num = hanoi(1, 3, n);
    cout << num << '\n';
    for (auto pii : arr) {
        cout << pii.first << ' ' << pii.second << '\n';
    }
}
