// SHARKFIRESTORM20058.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int n, q;
int map[65][65];
int new_map[65][65];
int arr[1001];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool visited[65][65] = { false };

int N;

void read_data() {
    cin >> n >> q;
    N = pow(2, n);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= q; i++) {
        cin >> arr[i];
    }
}

void rotate90(int x, int y, int size) {
    //size*size만큼의 임시 격자 만들어서
    vector<vector<int>> temp(size, vector<int>(size));

    // 90도 회전시켜 넣음
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp[j][size - i - 1] = map[x + i][y + j];
        }
    }

    // 회전된 데이터를 matrix에 복사
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            map[x + i][y + j] = temp[i][j];
        }
    }
}
void rotate_grid(int l) {

    int size = pow(2, l);
    
    for (int i = 1; i <= N; i+=size) {
        for (int j = 1; j <= N; j+=size) {
            //i,j를 우상단에 두는 size크기의 격자를 90도 돌림
            rotate90(i, j, size);
        }
    }
}

void melt() {
    int tmp_map[65][65];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            tmp_map[i][j] = map[i][j];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            
            int cnt = 0;

            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];

                if (ni<1 || nj<1 || ni>N || nj>N || map[ni][nj] == 0) {
                    continue;
                }
                cnt++;
            }

            if (cnt < 3 && tmp_map[i][j] > 0) {
                tmp_map[i][j]--;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j] = tmp_map[i][j];
        }
    }

}

void print_map(string str) {
    cout <<str<< '\n';
    for (int i = 1; i <= pow(2,n); i++) {
        for (int j = 1; j <= N; j++) {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}

int total() {
    int result = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            result+= map[i][j];
        }
        
    }
    return result;
}
int cnt_group(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    int cnt = 1;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if (nx<1 || ny<1 || nx>N || ny>N || map[nx][ny] == 0 || visited[nx][ny]) {
                continue;
            };

            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
            cnt++;
        }
    }
    return cnt;
}

int largest() {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] > 0 && !visited[i][j]) {
                int tmp = cnt_group(i, j);
                if (cnt < tmp) {
                    cnt = tmp;
                }
            }
            
        }
    }
    return cnt;
    
}

int main() {
    read_data();
    for (int i = 1; i <= q; i++) {
        //cout << i << '\n';
        rotate_grid(arr[i]);
        //print_map(to_string(pow(2,arr[i]))+"만큼 돌린 후: ");
        melt();
        //print_map("녹은 후");
    }

    cout << total() <<'\n';
    cout << largest();
}
    
