#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    //i가 j를 이겼는지, 졌는지
    vector<vector<int>> Map(n+1, vector<int>(n+1, 2));
    for(int i=1;i<=n;i++) {
        Map[i][i] = 0;
    }
    for(auto result: results) {
        Map[result[0]][result[1]] = 1;
        Map[result[1]][result[0]] = -1;
    }
    
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(Map[i][k]==1&&Map[k][j]==1) {
                    Map[i][j] = 1;
                    Map[j][i] = -1;
                }
            }
        }
    }
    
    
    int answer = 0;
//     for(int i=1;i<=n;i++) {
//         int j;
//         for(j=1;j<=n;j++) {
//             cout << Map[i][j] << ' ';
//         }
//         cout << '\n';
        
//     }
    
    for(int i=1;i<=n;i++) {
        int j;
        for(j=1;j<=n;j++) {
            if(Map[i][j]==2) break;
        }
        if(j==n+1) answer++;
    }
    return answer;
}