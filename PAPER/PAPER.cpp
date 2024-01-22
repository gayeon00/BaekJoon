// PAPER.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
    int n;
};

int map[129][129];
vector<Point> result;

bool detect(int x, int y, int n) {
    int color = map[x][y];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[x + i][y + j] != color) {
                return true;
            }
        }
    }

    return false;
}

void divide(int x, int y, int n) {
    /*result.erase(find(result.begin(), result.end(), point));*/

    if (!detect(x, y, n)) {
        result.push_back({ x,y,n });
        return;
    }

    divide(x, y, n / 2);
    divide(x + n / 2, y, n / 2);
    divide(x, y + n / 2, n / 2);
    divide(x + n / 2, y + n / 2, n / 2);
    
}

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    divide(1,1,N);

    int blue = 0;
    int white = 0;

    for (auto point : result) {
        if (map[point.x][point.y] == 1) {
            blue++;
        } else {
            white++;
        }
    }

    cout << white << '\n' << blue;

}
