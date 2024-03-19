// SW_ESCAPE1953.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M, R, C, L;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int possibles[8][4] = {
    {0,0,0,0},
    {1,1,1,1},
    {0,1,0,1},
    {1,0,1,0},
    {1,0,0,1},
    {1,1,0,0},
    {0,1,1,0},
    {0,0,1,1}
};

int main() {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N >> M >> R >> C >> L;
        int Map[50][50];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> Map[i][j];
            }
        }

        bool visited[50][50] = { false };
        queue<tuple<int, int, int>> q;
        q.push(make_tuple(R, C, 1));
        visited[R][C] = true;
        while (!q.empty() && get<2>(q.front()) < L) {
            tuple<int, int, int> now = q.front();
            q.pop();
            int x = get<0>(now);
            int y = get<1>(now);
            int level = get<2>(now);
            auto dir = possibles[Map[x][y]];

            for (int i = 0; i < 4; i++) {
                if (dir[i]) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    

                    //Map[nx][ny]가 Map[x][y]랑 연결되는지 봐야함
                    if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny]) {
                        if ((i == 0 || i == 1) && dir[i] == possibles[Map[nx][ny]][i + 2]) {
                            visited[nx][ny] = true;
                            q.push(make_tuple(nx, ny, level + 1));
                        } else if ((i == 2 || i == 3) && dir[i] == possibles[Map[nx][ny]][i - 2]) {
                            visited[nx][ny] = true;
                            q.push(make_tuple(nx, ny, level + 1));
                        }
                        
                    }
                }
                
                
            }

        }

        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j]) {
                    answer++;
                }
            }
        }

        cout << "#" << test_case << " " << answer << '\n';

    }
    return 0;
}