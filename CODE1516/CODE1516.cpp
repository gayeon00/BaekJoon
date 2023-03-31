// CODE1516.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print_data(vector<vector<int>>& A,
    vector<int>& indegree,
    vector<int>& selfBuild) {
    for (auto& a : A) {
        for (int i : a) {
            cout << i << ", ";
        }
        cout << '\n';
    }
    cout << '\n';

    for (int i : indegree) {
        cout << i << ", ";
    }

    cout << '\n';
    
    for (int i : selfBuild) {
        cout << i << ", ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> A;
    vector<int> indegree;
    vector<int> selfBuild;

    A.resize(N + 1);
    indegree.resize(N + 1);
    selfBuild.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> selfBuild[i]; //시간 데이터 저장

        while (true) {
            int tmp;
            cin >> tmp;
            if (tmp == -1) break;

            indegree[i]++; //차수 저장
            A[tmp].push_back(i); //인접리스트 저장
        }
    }

    //print_data(A, indegree, selfBuild);

    /*위상 정렬 수행*/
    queue<int> myQueue;
    for (int i = 1; i <= N; i++) {
        if (indegree[i]==0) myQueue.push(i);
    }

    vector<int> result;
    result.resize(N + 1);

    while (!myQueue.empty()) {
        int now = myQueue.front();
        myQueue.pop();

        for (int node : A[now]) {
            indegree[node]--;
            result[node] = max(result[node], result[now] + selfBuild[now]);
            if (!indegree[node]) myQueue.push(node);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << selfBuild[i] + result[i] << '\n';
    }
}