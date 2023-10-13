// CHICKEN15686.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits.h>

using namespace std;

typedef pair<int, int> pii;

int n, m;
int map[100][100];
vector<pii> chickenShops;
vector<pii> homes;
int result = INT_MAX;

void read_data() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];

            if (map[i][j] == 2) {
                chickenShops.push_back(make_pair(i, j));
            }

            if (map[i][j] == 1) {
                homes.push_back(make_pair(i, j));
            }
        }
    }
}

void printCombination(vector<pii>& combinations) {
    cout << "\n";
    for (auto i : combinations) {
        cout << i.first << ", " << i.second << "\n";
    }
}

//i,j지점과 combination중 제일 가까운 치킨집과의 거리를 구함
int findNearestChicken(int i, int j, vector<pii>& combinations) {
    int result = INT_MAX;

    for (auto c : combinations) {
        int dist = abs(i - c.first) + abs(j - c.second);

        if (dist < result) {
            result = dist;
        }
    }

    return result;
}

int totalChickenDistance(int map[][100], vector<pii>& combinations) {
    int result = 0;

    for (auto home : homes) {
        result += findNearestChicken(home.first, home.second, combinations);
    }
    
    return result;
}

void findCombination(vector<pii>& chickenShops, int start, int n, int r, vector<pii>& combinations) {
    if (r == 0) {
        //k개 다 찾음, combination에 들어있음
        //printCombination(combinations);
        int dist = totalChickenDistance(map, combinations);

        if (dist < result) {
            result = dist;
        }

        return;
    }

    for (int i = start; i <= n - r; i++) {
        combinations.push_back(chickenShops[i]);
        findCombination(chickenShops, i + 1, n, r - 1, combinations);
        combinations.pop_back();
    }
}


int main() {
    read_data();

    vector<pii> combinations;
    for (int k = 1; k <= m; k++) {
        findCombination(chickenShops, 0, chickenShops.size(), k, combinations);
    }
    

    cout << result;

    return 0;
}