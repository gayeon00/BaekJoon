// SWITCH1244.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    
    int switches[101] = { 0 };
    for (int i = 1; i <= N; i++) {
        cin >> switches[i];
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int sex;
        cin >> sex;
        int num;
        cin >> num;


        if (sex == 1) {
            int idx = num;
            while (idx <= N) {
                if (switches[idx] == 1) {
                    switches[idx] = 0;
                } else {
                    switches[idx] = 1;
                }
                idx += num;
            }
        } else if (sex == 2) {
            int step = 1;
            while (num - step > 0 && num + step <= N) {
                if (switches[num - step] != switches[num + step]) {
                    break;
                }
                step++;
            }
            step--;

            for (int i = num - step; i <= num + step; i++) {
                if (switches[i] == 1) {
                    switches[i] = 0;
                } else {
                    switches[i] = 1;
                }
            }
        }
    }

    // 출력 부분 수정
    for (int i = 1; i <= N; i++) {
        cout << switches[i];
        if (i % 20 == 0) // 20개 스위치마다 줄바꿈 (이 부분은 문제 요구사항에 따라 조정)
            cout << '\n';
        else if (i < N) // 마지막 스위치가 아니면 공백을 출력
            cout << ' ';
    }
    cout << '\n'; // 마지막에 줄바꿈 추가

    return 0;
}