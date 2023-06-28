// ATM11399.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N;
    cin >> N;

    priority_queue<int> q;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        q.push(tmp);
    }

    int idx = 1;
    int result = 0;

    while (!q.empty()) {
        result += q.top() * idx;
        q.pop();
        idx++;
    }

    cout << result;

    for (int i = 1; i < N; i++) {
        int insert_point = i;
        int insert_value = A[i];
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] < A[i]) {
                insert_point = j + 1;
                break;
            }
            if (j == 0) {
                insert_point = 0;
            }
        }

        //shift하기
        for (int j = i; j > insert_point; j--) {
            A[j] = A[j - 1];
        }

        //집어넣기
        A[insert_point] = insert_value;
    }


}