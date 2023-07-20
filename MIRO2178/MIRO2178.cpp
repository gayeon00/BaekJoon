// MIRO2178.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;
int N, M;
int A[101][101] = { 0 };
int visited[101][101] = { false };
int di[4] = { 1,0,-1,0 };
int dj[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;



int main() {
    cin >> N >> M;

    //입력
    string tmp;
    for (int i = 1; i <= N; i++) {
        cin >> tmp;
        for (int j = 1; j <= M; j++) {
            A[i][j] = tmp[j - 1] - '0';
        }
    }

    q.push({ 1,1 });
    visited[1][1] = true;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = now.first + di[k];
            int nj = now.second + dj[k];

            if (ni >= 1 && nj >= 1 && ni <= N && nj <= M) {
                if (!visited[ni][nj] && A[ni][nj] == 1) {
                    q.push({ ni,nj });
                    A[ni][nj] = A[now.first][now.second] + 1;
                    visited[ni][nj] = true;
                }
            }
        }
    }
    

    cout << A[N][M];
}
