// 17142LAB3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> pii;

struct node {
    int x;
    int y;
    int count;
};

int map[51][51];
int n, m;
int result = INT_MAX;

vector<pii> virus;

void read_data() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                virus.push_back(make_pair(i, j));
            }
        }
    }
}

void printCombination(vector<pii>& combination) {
    cout << '\n';
    for (auto i : combination) {
        cout << i.first << ", " << i.second << '\n';
    }
}

bool isPacked(bool visited[][51]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            //통로인데 바이러스가 없다면
            if (map[i][j] == 0 && !visited[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool isAllVirus(queue<node> q) {
    while (!q.empty()) {
        node front = q.front();
        q.pop();

        if (map[front.x][front.y] != 2) {
            return false;
        }
    }
    return true;
}

//이 조합에 대해 모든 빈칸에 바이러스 퍼트리는데 걸리는 시간 구하기
int getSpreadTime(vector<pii>& combination) {
    int dx[4] = { -1,0,1,0 };
    int dy[4] = { 0,1,0,-1 };

    bool visited[51][51] = { false };
    queue<node> q;

    for (auto i : combination) {
        q.push({i.first, i.second, 0});
        visited[i.first][i.second] = true;
    }

    //한 배치에 해당하는 놈들은 시간이 같아야 함. 초반 q의 앞 3개는 result가 1로 같아야함
    while (!q.empty()) {
        node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx<1 || ny<1 || nx>n || ny>n || map[nx][ny] == 1 || visited[nx][ny]) {
                continue;
            }

            q.push({ nx,ny,now.count + 1 });
            visited[nx][ny] = true;
        }

        //q에 남은 얘들이 다 바이러스고, 더 빈공간이 없으면
        if (isAllVirus(q) && isPacked(visited)) {
            return now.count;
        }

        //마지막 이면
        if (q.empty()) {
            //다 퍼트려서 마지막인지, 다 못퍼트렸는데 더이상 퍼트릴 수 없어서 마지막인지 구분해야함
            if (!isPacked(visited)) {
                return -1;
            } else {
                return now.count;
            }
            
        }
    }
}

void findCombination(vector<pii>& virus, int start, int n, int r, vector<pii>& combination) {
    if (r == 0) {
        //m개 다 선택함 -> combination에 담겨있음
        //printCombination(combination);

        //이 조합에 대해 모든 빈칸에 바이러스 퍼트리는데 걸리는 시간 구하기
        int spreadTime = getSpreadTime(combination);
        //cout << spreadTime << '\n';
        if (spreadTime != -1 && spreadTime < result) {
            result = spreadTime;
        }

        return;
    }

    for (int i = start; i <= n - r; i++) {
        combination.push_back(virus[i]);
        findCombination(virus, i + 1, n, r - 1, combination);
        combination.pop_back();
    }
}

int main() {
    read_data();

    vector<pii> combination;
    findCombination(virus, 0, virus.size(), m, combination);

    if (result == INT_MAX) {
        cout << -1;
    } else {
        cout << result;
    }

    //vector<pii> tmp_group = { {1,1},{2,6},{5,4} };
    //cout << getSpreadTime(tmp_group);
}
