// SHARKTORNADO20057.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int n, result = 0;
int map[500][500] = { 0 };

int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

void read_data() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
}

void print_map() {
    cout << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

void spread(int x, int y, int direction) {
    int nx = x + dx[direction];
    int ny = y + dy[direction];
    int sand = map[nx][ny];
    int dir = 0;

    int alpha = sand;
    //여기 있던 모든 모래가 이동
    map[nx][ny] = 0;

    int mx = 0, my = 0;

    //시계방향 135도 +1, +1로 1% 이동↗️
    dir = (direction + 5) % 8;

    mx = nx + dx[dir]; my = ny + dy[dir];
    if (mx >= 1 && my >= 1 && mx <= n && my <= n) {
        map[mx][my] += (int)(sand * 0.01);
    } else {
        result += (int)(sand * 0.01);
    }
    
    alpha -= (int)(sand * 0.01);

    //반시계방향 135도 +1 +1로 1% 이동↘️
    dir = (direction + 3) % 8;
    
    mx = nx + dx[dir]; my = ny + dy[dir];
    if (mx >= 1 && my >= 1 && mx <= n && my <= n) {
        map[mx][my] += (int)(sand * 0.01);
    } else {
        result += (int)(sand * 0.01);
    }

    alpha -= (int)(sand * 0.01);

    //시계방향 45도 +1,+1로 10% 이동↖️
    dir = (direction + 7) % 8;
    
    mx = nx + dx[dir]; my = ny + dy[dir];
    if (mx >= 1 && my >= 1 && mx <= n && my <= n) {
        map[mx][my] += (int)(sand * 0.1);
    } else {
        result += (int)(sand * 0.1);
    }

    alpha -= (int)(sand * 0.1);

    //반시계방향 45도 +1,+1로 10% 이동↙️
    dir = (direction + 1) % 8;
    
    mx = nx + dx[dir]; my = ny + dy[dir];
    if (mx >= 1 && my >= 1 && mx <= n && my <= n) {
        map[mx][my] += (int)(sand * 0.1);
    } else {
        result += (int)(sand * 0.1);
    }

    alpha -= (int)(sand * 0.1);

    //시계방향 90도 +2로 2%이동
    dir = (direction + 6) % 8;
    
    mx = nx + 2 * dx[dir]; my = ny + 2 * dy[dir];
    if (mx >= 1 && my >= 1 && mx <= n && my <= n) {
        map[mx][my] += (int)(sand * 0.02);
    } else {
        result += (int)(sand * 0.02);
    }

    alpha -= (int)(sand * 0.02);
    
    //시계방향 90도 +1로 7%이동
    mx = nx + dx[dir]; my = ny + dy[dir];
    if (mx >= 1 && my >= 1 && mx <= n && my <= n) {
        map[mx][my] += (int)(sand * 0.07);
    } else {
        result += (int)(sand * 0.07);
    }

    alpha -= (int)(sand * 0.07);
    
    //반시계방향 90도 +2로 2%이동
    dir = (direction + 2) % 8;
    
    mx = nx + 2 * dx[dir]; my = ny + 2 * dy[dir];
    if (mx >= 1 && my >= 1 && mx <= n && my <= n) {
        map[mx][my] += (int)(sand * 0.02);
    } else {
        result += (int)(sand * 0.02);
    }

    alpha -= (int)(sand * 0.02);
    
    //반시계방향 90도 +1로 7%이동
    mx = nx + dx[dir]; my = ny + dy[dir];
    if (mx >= 1 && my >= 1 && mx <= n && my <= n) {
        map[mx][my] += (int)(sand * 0.07);
    } else {
        result += (int)(sand * 0.07);
    }

    alpha -= (int)(sand * 0.07);
    
    //동일방향 +2로 5%이동
    dir = direction;
    
    mx = nx + 2 * dx[dir]; my = ny + 2 * dy[dir];
    if (mx >= 1 && my >= 1 && mx <= n && my <= n) {
        map[mx][my] += (int)(sand * 0.05);
    } else {
        result += (int)(sand * 0.05);
    }

    alpha -= (int)(sand * 0.05);

    //동일방향 +1로 alpha이동
    mx = nx + dx[dir]; my = ny + dy[dir];
    if (mx >= 1 && my >= 1 && mx <= n && my <= n) {
        map[mx][my] += alpha;
    } else {
        result += alpha;
    }

    
    
}

void tornado() {
    int x = (n + 1) / 2;
    int y = (n + 1) / 2;

    int direction = 0, move_count = 0, number = 0;
    int dist = 1;

    while (true) {
        move_count++;
        for (int i = 0; i < dist; i++) {
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            if (nx == 1 && ny == 0) {
                return;
            }
            number++;
            //map[nx][ny] = number;
            if (map[nx][ny] > 0) {
                spread(x, y, direction);
            }
            x = nx; y = ny;
        }

        if (move_count == 2) {
            dist++;
            move_count = 0;
        }

        direction = (direction + 2) % 8;
    }
}


int main() {
    read_data();
    
    tornado();
    //print_map();
    cout << result;
}
