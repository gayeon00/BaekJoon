// GUITAR2343.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    int start = 0, end = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (start < A[i]) {
            start = A[i];
        }
        end += A[i];
    }

    while (start <= end) {
        int mid = (start + end) / 2;
        int sum = 0;
        int count = 0;

        //middle값으로 모든 레슨을 저장할수 있는지 확인
        for (int i = 0; i < N; i++) {
            sum += A[i];

            //저장하다가, mid보다 합이 커지면 블루레이 카운트 증가하고, 새 블루레이에 담는다(sum=0)
            if (sum > mid) {
                count++;
                sum = A[i];
            }

            
        }

        //마지막 블루레이에 담긴 게 있다면 블루레이 카운트 증가
        if (sum != 0) {
            count++;
        }

        //블루레이가 더 필요하면 모자라다는 뜻이니까 용량 증가
        if (count > M) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << start;
}
