// QUADTREE1992.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

int map[65][65] = { 0 };
string result;

bool isChunk(int x, int y, int n) {
    int flag = map[x][y];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (flag != map[x + i][y + j])
                return false;
        }
    }
    return true;
}

void compress(int x, int y, int n) {
    

    if (isChunk(x, y, n)) {
        result.push_back(map[x][y]+'0');
    } else {
        result.push_back('(');
        compress(x, y, n / 2);
        compress(x, y + n / 2, n / 2);
        compress(x + n / 2, y, n / 2);
        
        compress(x + n / 2, y + n / 2, n / 2);
        result.push_back(')');

    }
    
}

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 1; j <= N; j++) {
            map[i][j] = tmp[j - 1] - '0';
        }
    }

    compress(1, 1, N);

    cout << result;
}
