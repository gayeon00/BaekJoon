// NM15649.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 8;
int N, M;
int arr[MAX];
bool is_used[MAX + 1];//숫자 사용 여부를 저장하는 배열

void read_data() {
    cin >> N >> M;
    //1부터 N까지의 수 중 M개로 이루어진 모든 순열 ㄱㄱ
}

void backtrack(int k) { //k는 현재까지 선택한 원소의 개수
    if (k == M) { //M개의 원소를 모두 택한 경우
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) { //1~N까지의 수중
        if (!is_used[i]) { //i가 아직 선택되지 않은 원소의 경우
            arr[k] = i; //k번째 자리에 i를 채워넣음
            is_used[i] = true; //i사용했다고 표시
            backtrack(k + 1); //다음 자리 선택을 위해 k+1을 인자로 넘겨줌
            is_used[i] = false; 
            //재귀호출에서 돌아오면 사용하지 않은 걸로 변경
            //다시 이전 상태로 되돌아가기 위한 준비를하는 것! -> 모든 경우의 수 탐색 가능!!
        }
    }
}

void solve() {
    backtrack(0);
}

int main() {
    read_data();
    solve();
}
