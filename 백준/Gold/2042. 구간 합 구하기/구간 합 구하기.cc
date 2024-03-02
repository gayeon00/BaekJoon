// GUGAN2042.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//M: 수의 변경이 일어나는 횟수, K: 구간의 합을 구하는 횟수
int N, M, K;
vector<long long> tree;
int treeHeight = 0;
int treeSize = 0;
int leafNodeStartIndex = 0;

void setTree(int i) {
    while (i != 1) {
        tree[i / 2] += tree[i];
        i--;
    }
}

void read_data() {
    cin >> N >> M >> K;

    int length = N;
    while (length!=0) {
        length /= 2;
        treeHeight++;
    }

    treeSize = int(pow(2, treeHeight + 1));
    tree.resize(treeSize + 1);
    leafNodeStartIndex = treeSize / 2 - 1;

    //리프 노드 집어넣기
    for (int i = 1; i <= N; i++) {
        cin >> tree[leafNodeStartIndex + i];
    }

    setTree(treeSize - 1);
}


void change(int index, long number) {
    //index번째 수를 number로 바꾸기
    long diff = number - tree[index];

    while (index>0) {
        tree[index] += diff;
        index /= 2;
    }
}

void gugan(int start, int end) {
    long result = 0;

    while (start<=end) {
        if (start % 2 == 1) {
            result += tree[start];
            start++;
        }
        if (end % 2 == 0) {
            result += tree[end];
            end--;
        }

        start /= 2;
        end /= 2;
    }

    cout << result<< '\n';
}

void solve() {
    for (int i = 0; i < M + K; i++) {
        long a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            change(leafNodeStartIndex + b, c);
        } else if (a == 2) {
            gugan(leafNodeStartIndex + b, leafNodeStartIndex + c);
        }
    }
}


int main(){
    read_data();
    solve();
}
