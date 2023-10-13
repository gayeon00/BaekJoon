// MAGICIANSHARKCOPY23290.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int, int> pii;

struct fish {
    int x;
    int y;
    int d;

    bool operator==(const fish &f) const {
        return (x == f.x && y == f.y && d == f.d);
    }
};

int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

int dsx[4] = { -1,0,1,0 };
int dsy[4] = { 0,-1,0,1 };
vector<fish> map[5][5];
pair<int, bool> smell[5][5];
int m, s;
vector<fish> fishes;
vector<fish> original_fishes;
int sx, sy;
int result_eaten = 0;
vector<int> result_permutation;
pii result_s_position;

void read_data();
void magic();
void fish_move();
int count_eat_fish(vector<int>& permutation);
void eat_fish(vector<int>& permutation, int cnt);
string dict(vector<int>& permutation);
void find_permutation(int directions[], int r, bool used[], vector<int>& permutation, int cnt);
void shark_move(int);
void erase_smell(int cnt);
void magic_complete();
void print_map();
void print_fishes();

//잘못해따!!! magic함수에서 map에 있는 물고기들을 복사해야함!(fishes로 하면 안됨)

int main() {
    read_data();

    for (int i = 1; i <= s; i++) {
        magic();
        fish_move();
        shark_move(i);
        erase_smell(i);
        magic_complete();
    }
    
    /*print_map();
    print_fishes();*/
    cout << fishes.size();
}

void read_data() {
    cin >> m >> s;
    for (int i = 0; i < m; i++) {
        fish f;
        cin >> f.x >> f.y >> f.d;

        fishes.push_back(f);
        map[f.x][f.y].push_back(f);
    }
    cin >> sx >> sy;

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            smell[i][j] = make_pair(0, false);
        }
    }
}

//현재 fishes 저장
void magic() {
    for (auto f : fishes) {
        original_fishes.push_back(f);
    }
}


//물고기가 한칸 이동
void fish_move() {

    for (int i = 0; i < fishes.size(); i++) {
        fish f = fishes[i];

        int x = f.x;
        int y = f.y;
        int d = f.d;

        int n = 8;
        while (n--) {
            int nx = x + dx[d - 1];
            int ny = y + dy[d - 1];


            //out of range도 아니고, 냄새가 남은 칸도 아니고, 상어가 있는칸도 아니면
            if (nx >= 1 && ny >= 1 && nx <= 4 && ny <= 4 && !smell[nx][ny].second && (nx != sx || ny != sy)) {
               
                //map[f.x][f.y]에서 제거하기
                vector<fish>::iterator iter = find(map[x][y].begin(), map[x][y].end(), f);
                if (iter == map[x][y].end()) {
                    cout << "what\n";
                } else {
                    map[x][y].erase(iter);
                }
                

                //f 업데이트하기
                f.x = nx; f.y = ny; f.d = d;

                //fishes는 업데이트하기
                fishes[i] = f;

                //map[nx][ny]에 넣기
                map[nx][ny].push_back(f);
                
                break;
            } else {
                d = (d + 7) % 8;
            }
        }
    }
}

int count_eat_fish(vector<int>& permutation) {
    int result = 0;
    bool visited[5][5] = { false };
    int x = sx;
    int y = sy;
    for (int direction : permutation) {
        int nx = x + dsx[direction - 1];
        int ny = y + dsy[direction - 1];

        if (nx < 1 || ny < 1 || nx > 4 || ny > 4 || visited[nx][ny]) {
            continue;
        }

        visited[nx][ny] = true;
        x = nx; y = ny;
        if (map[nx][ny].size() > 0) {
            result += map[nx][ny].size();
        }
    }
    return result;
}

void eat_fish(vector<int>& permutation, int cnt) {
    for (int direction : permutation) {
        int nx = sx + dsx[direction - 1];
        int ny = sy + dsy[direction - 1];

        if (nx < 1 || ny < 1 || nx > 4 || ny > 4) {
            continue;
        }
        
        sx = nx; sy = ny;
       
        if (map[nx][ny].size() > 0) {
            for (auto f : map[nx][ny]) {
                auto iter = find(fishes.begin(), fishes.end(), f);
                fishes.erase(iter);
            }
            map[nx][ny].clear();
            smell[nx][ny] = make_pair(cnt, true);
        }
    }
}

string dict(vector<int>& permutation) {
    string str = "";
    for (auto i : permutation) {
        str += to_string(i);
    }
    return str;
}

void find_permutation(int directions[], int r, bool used[], vector<int>& permutation, int cnt) {
    if (permutation.size() == r) {
        for (auto i : permutation) {
            cout << i << " ";
        }
        cout << '\n';
        //permutation안에 수열이 담겨있음
        int eaten = count_eat_fish(permutation);

        if (result_eaten < eaten) {
            result_eaten = eaten;
            result_permutation = permutation;
        } else if (result_eaten == eaten && dict(result_permutation) > dict(permutation)) {
            result_eaten = eaten;
            result_permutation = permutation;
        }

        return;
    }

    for (int i = 0; i < 4; i++) {
        permutation.push_back(directions[i]);
        find_permutation(directions, r, used, permutation, cnt);
        permutation.pop_back();
        //if (!used[i]) {
        //    used[i] = true;
        //    permutation.push_back(directions[i]);
        //    find_permutation(directions, r, used, permutation, cnt);
        //    permutation.pop_back();
        //    used[i] = false;
        //}
    }
}

void shark_move(int cnt) {
    //sx, sy에 대해 3번 이동해서 제일 물고기를 많이 먹는 방법을 구하기
    //먼저 permutation구하기
    int directions[4] = { 1,2,3,4 };
    bool used[4] = { false, };
    vector<int> permutation;

    find_permutation(directions, 3, used, permutation, cnt);
    cout << "최적 방향: ";
    for (auto i : result_permutation) {
        cout << i << " ";
    }
    cout << '\n';
    eat_fish(result_permutation, cnt);
    

}

void erase_smell(int cnt) {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (smell[i][j].first == cnt-2) {
                smell[i][j] = make_pair(0, false);
            }
        }
    }
}

void magic_complete() {
    for (auto f : original_fishes) {
        map[f.x][f.y].push_back(f);
        fishes.push_back(f);
    }
}

void print_map() {
    cout << '\n';
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            for (auto i : map[i][j]) {
                cout << i.x << " " << i.y << " " << i.d << "\n";
            }
        }
    }
}
void print_fishes() {
    cout << '\n';
    for (auto f : fishes) {
        cout << f.x << " " << f.y << " " << f.d << "\n";
    }
}
