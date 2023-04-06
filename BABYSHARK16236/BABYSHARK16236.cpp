// BABYSHARK16236.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

using namespace std;

struct Point {//위치
    int x, y, d;//x,y,(x,y)까지 이동하기 위한 거리
};

int N;
int Map[20][20];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int result = 0;//최종 결과값
int x, y; //상어위치
const int INF = 876543;


void read_data() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Map[i][j];
            //상어 위치
            if (Map[i][j] == 9) {
                x = i, y = j;
                Map[i][j] = 0;
            }
        }
    }
}


void solve() {
    int babysize = 2, cnt = 2;
    Point minPt = { x,y,0 }; //거리가 최소인 점! -> 업데이트 될거임!

    do {//최소거리의 상어를 언제 먹을지 모르기 때문에 무한으로 돌림
        bool visited[20][20] = { false }; //방문여부 저장
        queue<Point> q;//BFS위한 큐
        visited[minPt.x][minPt.y] = true;
        q.push({ minPt.x, minPt.y, 0 });
        minPt.d = INF; //최소 거리를 충분히 크게 초기화

        while (!q.empty()) {
            Point curr = q.front();
            q.pop();

            //더 큰 거리라면 더 이상 없음!
            if (curr.d > minPt.d) break;
            if (Map[curr.x][curr.y] > babysize) continue;
            //먹을 수 있는 물고기에 도달
            if (Map[curr.x][curr.y] != 0 && Map[curr.x][curr.y] < babysize) {
                //최소 거리라면
                if (curr.d < minPt.d) {
                    minPt = curr;
                } else if (curr.d == minPt.d) { //최소거리가 여러개인 경우
                    //가장 위에 있는거
                    if (curr.x < minPt.x) {
                        minPt = curr;
                    } //높이가 같다면 가장 왼쪽에 있는거
                    else if (curr.x == minPt.x && curr.y < minPt.y) {
                        minPt = curr;
                    }
                }
                //최소거리 찾았으니까 더 탐색할 필요 없음
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int nx = curr.x + dx[i];
                int ny = curr.y + dy[i];

                if ( nx<0 || ny<0 || nx>N - 1 || ny>N - 1) continue;
                if (visited[nx][ny]) continue;
                visited[nx][ny] = true;
                q.push({ nx,ny,curr.d + 1 });
            }
        }

        //물고기 찾았다면
        if (minPt.d != INF) {
            result += minPt.d;
            --cnt;
            if (cnt == 0) {
                babysize++;
                cnt = babysize;
            }
            Map[minPt.x][minPt.y] = 0;
        }

    } while (minPt.d != INF);


    cout << result << endl;
}

int main() {
    read_data();
    solve();
}