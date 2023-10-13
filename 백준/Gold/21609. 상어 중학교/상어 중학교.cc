// SHARKMIDDLE21609.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N, M;
int Map[21][21];
int result = 0;

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,-1,0,1 };

vector<pii> group;

void read_data();
bool find_group();
void delete_group();
void rotate();
void gravitify();
void print_map();
int count_rainbow(vector<pii>);
pii get_represent(vector<pii>);

int main()
{
    read_data();
    
    while (true) {
        group.clear();
        
        bool flag = find_group();
        if (flag) {
            delete_group();
            gravitify();
            rotate();
            gravitify();
        } else {
            break;
        }
    }

    cout << result;
    
}

int count_rainbow(vector<pii> group) {
    int result = 0;
    for (auto i : group) {
        if (Map[i.first][i.second] == 0) {
            result++;
        }
    }
    return result;
}

pii get_represent(vector<pii> group) {
    sort(group.begin(), group.end());

    for (pii i: group) {
        if (Map[i.first][i.second] != 0) {
            return i;
        }
    }
}

bool find_group() {
    bool visited[21][21] = { false };

    bool found = false;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            //r,c를 시작점으로 하는 그룹
            //cout << "\n";
            vector<pii> tmp_group;

            if (visited[r][c] || Map[r][c] <= 0) {
                continue;
            }

            visited[r][c] = true;

            queue<pii> q;
            q.push(make_pair(r, c));

            while (!q.empty()) {
                pii now = q.front();
                q.pop();

                //cout << now.first << ", " << now.second << '\n';
                tmp_group.push_back(now);

                for (int i = 0; i < 4; i++) {
                    int nx = now.first + di[i];
                    int ny = now.second + dj[i];

                    if (nx<1 || ny<1 || nx>N || ny>N || Map[nx][ny] == -1) {
                        continue;
                    }


                    if (!visited[nx][ny] && (Map[nx][ny] == 0 || Map[nx][ny] == Map[r][c])) {
                        q.push(make_pair(nx, ny));
                        visited[nx][ny] = true;
                    }
                }
            }

            // 블록 그룹 찾기
            if (tmp_group.size() > 1) {
                found = true;

                if (tmp_group.size() > group.size()) {
                    group = tmp_group;
                } else if (tmp_group.size() == group.size() && count_rainbow(tmp_group) > count_rainbow(group)) {
                    group = tmp_group;
                } else if (tmp_group.size() == group.size() && count_rainbow(tmp_group) == count_rainbow(group) && get_represent(tmp_group) > get_represent(group)) {
                    group = tmp_group;
                }
            }

            //무지개 칸은 다시 사용할 수 있도록 변경해주기
            for (auto i : tmp_group) {
                if (Map[i.first][i.second] == 0) {
                    visited[i.first][i.second] = false;
                }
            }
        }
    }
    
    return found;
}

void delete_group() {
    result += group.size() * group.size();
    for (auto i : group) {
        Map[i.first][i.second] = -2;
    }
}

void read_data() {
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> Map[i][j];
        }
    }
}

void rotate() {
    int tmp[21][21];

    //tmp에 임시로 돌린 것 담기
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            tmp[N + 1 - j][i] = Map[i][j];
        }
    }

    //다시 tmp로부터 옮겨담기
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            Map[i][j] = tmp[i][j];
        }
    }
}

void gravitify() {
    int tmp[21][21];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            tmp[i][j] = -2;
        }
    }

    for (int j = 1; j <= N; j++) {
        //한 열에 대해
        queue<int> q;
        int spot = N;
        for (int i = N; i >=1; i--) {

            if (Map[i][j] == -1) {
                tmp[i][j] = -1;
                while (!q.empty()) {
                    tmp[spot--][j] = q.front();
                    q.pop();
                }
                spot = i - 1;
            } else if (Map[i][j] != -2) {
                q.push(Map[i][j]);
            }
        }

        //남은 q털기 
        while (!q.empty()) {
            tmp[spot--][j] = q.front();
            q.pop();
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            Map[i][j] = tmp[i][j];
        }
    }
}


void print_map() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << Map[i][j] << " ";
        }
        cout << "\n";
    }
}