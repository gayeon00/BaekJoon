// TSP2098.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <limits.h>

using namespace std;

int n;
int W[16][16];
int D[16][(1 << 16)];
int tsp(int c, int v);
int INF = 1000000 * 16 + 1;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> W[i][j];
        }
    }

    cout << tsp(0, 1);
}

int tsp(int c, int v) {
    // 모든 노드를 방문했다면
    if (v == ((1 << n) - 1)) {
        return W[c][0] == 0 ? INF : W[c][0];
    }

    //이미 계산한 노드라면
    if (D[c][v] != 0) {
        return D[c][v];
    }

    int min_val = INF;
    for (int i = 0; i < n; i++) {
        //방문한 적 없고 갈 수 있는 도시일 때
        if ((v & (1 << i)) == 0 && W[c][i] != 0) {
            min_val = min(min_val, tsp(i, (v | (1 << i))) + W[c][i]);
        }
    }
    
    return D[c][v] = min_val;
} 
