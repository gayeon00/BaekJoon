// 204812100.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> board;
int N;
int maxNumber = -1;

void shift(int i, vector<vector<int>>& board) {
    queue<int> q;
    switch (i) {
        //좌측으로
        case 0:
            for (int i = 0; i < N; i++) {
                //큐로 순서 맞춰 옮기기
                for (int j = 0; j < N; j++) {
                    if (board[i][j] != 0) q.push(board[i][j]);
                    board[i][j] = 0;
                }

                //좌측으로 한칸 옮긴 모양으로 재배치 시작!
                int index = 0; //첨위치 = 0

                while (!q.empty()) {
                    int num = q.front();
                    q.pop();
                    //index위치가 비어있으면 그냥 넣어
                    if (board[i][index] == 0) {
                        board[i][index] = num;
                    }
                    //넣을 숫자랑 동일한 숫자면 그 위치에 병합
                    else if (board[i][index] == num) {
                        board[i][index] *= 2;
                        //다음 위치로 넘어가기
                        index++;
                    }
                    //다른 숫자가 들어있으면 다음 칸에 넣기
                    else {
                        index++;
                        board[i][index] = num;
                    }
                }
            }
            break;
            //우
        case 1:
            for (int i = 0; i < N; i++) {
                //큐로 순서 맞춰 옮기기
                for (int j = N-1; j >= 0; j--) {
                    if (board[i][j] != 0) q.push(board[i][j]);
                    board[i][j] = 0;
                }

                //좌측으로 한칸 옮긴 모양으로 재배치 시작!
                int index = N-1; //첨위치 = 0

                while (!q.empty()) {
                    int num = q.front();
                    q.pop();
                    //index위치가 비어있으면 그냥 넣어
                    if (board[i][index] == 0) {
                        board[i][index] = num;
                    }
                    //넣을 숫자랑 동일한 숫자면 그 위치에 병합
                    else if (board[i][index] == num) {
                        board[i][index] *= 2;
                        //다음 위치로 넘어가기
                        index--;
                    }
                    //다른 숫자가 들어있으면 다음 칸에 넣기
                    else {
                        index--;
                        board[i][index] = num;
                    }
                }
            }
            break;
        //상 위쪽부터 넣음! 0행부터!
        case 2:
            //i: 열 j: 행
            for (int i = 0; i < N; i++) {
                //큐로 순서 맞춰 옮기기
                for (int j = 0; j < N; j++) {
                    if (board[j][i] != 0) q.push(board[j][i]);
                    board[j][i] = 0;
                }

                //좌측으로 한칸 옮긴 모양으로 재배치 시작!
                int index = 0; //첨위치 = 0

                while (!q.empty()) {
                    int num = q.front();
                    q.pop();
                    //index위치가 비어있으면 그냥 넣어
                    if (board[index][i] == 0) {
                        board[index][i] = num;
                    }
                    //넣을 숫자랑 동일한 숫자면 그 위치에 병합
                    else if (board[index][i] == num) {
                        board[index][i] *= 2;
                        //다음 위치로 넘어가기
                        index++;
                    }
                    //다른 숫자가 들어있으면 다음 칸에 넣기
                    else {
                        index++;
                        board[index][i] = num;
                    }
                }
            }
            break;

        //하
        case 3:
            for (int i = 0; i < N; i++) {
                //큐로 순서 맞춰 옮기기
                for (int j = N-1; j >= 0; j--) {
                    if (board[j][i] != 0) q.push(board[j][i]);
                    board[j][i] = 0;
                }

                //좌측으로 한칸 옮긴 모양으로 재배치 시작!
                int index = N-1; //첨위치 = 0

                while (!q.empty()) {
                    int num = q.front();
                    q.pop();
                    //index위치가 비어있으면 그냥 넣어
                    if (board[index][i] == 0) {
                        board[index][i] = num;
                    }
                    //넣을 숫자랑 동일한 숫자면 그 위치에 병합
                    else if (board[index][i] == num) {
                        board[index][i] *= 2;
                        //다음 위치로 넘어가기
                        index--;
                    }
                    //다른 숫자가 들어있으면 다음 칸에 넣기
                    else {
                        index--;
                        board[index][i] = num;
                    }
                }
            }
            break;
        default:
            break;
    }
}

void DFS(int cnt, vector<vector<int>>& board) {
    if (cnt == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                maxNumber = max(maxNumber, board[i][j]);
            }
        }
        return;
    }

    //board원상복구용 백업
    int backUp[21][21];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            backUp[i][j] = board[i][j];
        }
    }

    //4가지 방향 중 선택
    for (int i = 0; i < 4; i++) {
        shift(i, board);
        DFS(cnt + 1, board);
        //다시 돌아와서 다른 방향으로 가보자
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = backUp[i][j];
            }
        }
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        vector<int> tmp;
        for (int j = 0; j < N; j++) {
            int t;
            cin >> t;
            tmp.push_back(t);
        }
        board.push_back(tmp);
    }
    
    DFS(0, board);
    cout << maxNumber;
}