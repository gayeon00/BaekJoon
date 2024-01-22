// SHARKBLIZZARD21611.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>


using namespace std;

typedef pair<int, int> pii;

struct Magic {
    int d;
    int s;
};

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int n, m;
int map[50][50];
vector<pii> indexes;
vector<Magic> magics;

int cnt_1 = 0, cnt_2 = 0, cnt_3 = 0;
void read_data() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        Magic m;
        cin >> m.d >> m.s;
        m.d--;
        magics.push_back(m);
    }


}
void tornado() {
    indexes.resize(n * n);
    indexes[0] = make_pair((n + 1) / 2, (n + 1) / 2);

    int x = (n + 1) / 2; int y = (n + 1) / 2;
    
    int sx[4] = { 0,1,0,-1 };
    int sy[4] = { -1,0,1,0 };
    int direction = 0, dist = 1, cnt = 0, number = 0;
    while (true) {
        cnt++;

        for (int i = 0; i < dist; i++) {
            int nx = x + sx[direction];
            int ny = y + sy[direction];

            if (nx == 1 && ny == 0) {
                //토네이도 끝
                return;
            }
            number++;
            indexes[number] = make_pair(nx, ny);
            x = nx; y = ny;
        }

        if (cnt == 2) {
            dist++;
            cnt = 0;
        }

        direction = (direction + 1) % 4;
        
    }

}
void move() {

    vector<int> tmp;
    queue<int> map_numbers;

    for (int i = 1; i < indexes.size(); i++) {
        pii now = indexes[i];

        if (map[now.first][now.second] == 0) {
            for (auto t : tmp) {
                map_numbers.push(t);
            }
            tmp.clear();
        } else {
            tmp.push_back(map[now.first][now.second]);
        }
    }

    for (auto t : tmp) {
        map_numbers.push(t);
    }

    //map비우고
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map[i][j] = 0;
        }
    }

    //map_numbers넣기
    for (int i = 1; i < indexes.size(); i++) {
        int x = indexes[i].first;
        int y = indexes[i].second;

        if (map_numbers.empty()) {
            break;
        } 

        map[x][y] = map_numbers.front();
        map_numbers.pop();
    }
    
}
void print_map(string str) {
    cout << str <<'\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

void ice(int ith) {
    Magic m = magics[ith];
    for (int i = 1; i <= m.s; i++) {
        int nx = (n + 1) / 2 + i * dx[m.d];
        int ny = (n + 1) / 2 + i * dy[m.d];

        if (nx >= 1 && ny >= 1 && nx <= n && ny <= n) {
            map[nx][ny] = 0;
        }
    }
}

vector<pii> find_explosive() {
    int before = -1;
    vector<pii> tmp;
    vector<pii> result;

    for (int i = 1; i < indexes.size(); i++) {
        pii now = indexes[i];

        if (map[now.first][now.second] == 0) {
            continue;
        }

        if (map[now.first][now.second] != before) {
            if (tmp.size() >= 4) {
                for (auto t : tmp) {
                    result.push_back(t);
                }
            } 
            tmp.clear();
        }
        before = map[now.first][now.second];
        tmp.push_back(now);
    }

    if (tmp.size() >= 4) {
        for (auto t : tmp) {
            result.push_back(t);
        }
    }

    return result;
}

void explode(vector<pii>& explosives) {
    for (auto t : explosives) {

        switch (map[t.first][t.second]) {
            case 1:
                cnt_1++;
                break;
            case 2:
                cnt_2++;
                break;
            case 3:
                cnt_3++;
                break;

        }
        
        map[t.first][t.second] = 0;
    }
}

void change() {
    
    int before = -1;
    vector<pii> tmp;
    queue<int> result;

    for (int i = 1; i < indexes.size(); i++) {
        pii now = indexes[i];

        if (map[now.first][now.second] == 0) {
            continue;
        }

        if (map[now.first][now.second] != before) {
            if (!tmp.empty()) {
                //tmp에 있는 얘들 확인해서 구슬 A, B로 바꾸기
                int A = tmp.size();
                int B = map[tmp[0].first][tmp[0].second];
                result.push(A); result.push(B);
            }
            
            tmp.clear();
        }
        before = map[now.first][now.second];
        tmp.push_back(now);
    }

    //tmp에 있는 얘들 확인해서 구슬 A, B로 바꾸기
    if (!tmp.empty()) {
        int A = tmp.size();
        int B = map[tmp[0].first][tmp[0].second];
        result.push(A); result.push(B);

        //result에 있는 숫자들 map에 옮겨주기 
        //map비우고
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                map[i][j] = 0;
            }
        }

        //map_numbers넣기
        for (int i = 1; i < indexes.size(); i++) {
            int x = indexes[i].first;
            int y = indexes[i].second;

            if (result.empty()) {
                break;
            }

            map[x][y] = result.front();
            result.pop();
        }
    }
    
}
int main() {
    //m만큼 d랑 s받아야함
    read_data();
    tornado();
    for (int i = 0; i < m; i++) {
        //cout <<"\n\n" << i+1 << "번째---- - \n";
        ice(i);
        //print_map("얼음파편 후: ");
        move();
        //print_map("이동 후(1): ");
        
        while (true) {
            vector<pii> explosives = find_explosive();
            
            if (explosives.size() == 0) {
                break;
            }
            explode(explosives);
            //print_map("폭팔 후: ");
            move();
            //print_map("이동 후(2): ");
        }
        
        change();
        //print_map("변화 후:");
        
    }
    cout << 1 * cnt_1 + 2 * cnt_2 + 3 * cnt_3;
}

