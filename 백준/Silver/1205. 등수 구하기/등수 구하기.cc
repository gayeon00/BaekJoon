// RANK1205.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int N, score, P;
    cin >> N >> score >> P;

    vector<int> scores;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        scores.push_back(tmp);
    }

    if (scores.size() < P) {
        int rank = count_if(scores.begin(), scores.end(), [score](int i) {return i > score; }) + 1;
        cout << rank << '\n';
    } else {
        sort(scores.begin(), scores.end());
        //제일 작은거
        if (scores[0] < score) {
            int rank = count_if(scores.begin(), scores.end(), [score](int i) {return i > score; }) + 1;
            cout << rank << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}
