#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[502][502];

int solution(vector<vector<int>> triangle) {
    int leafCnt = triangle.size();
    for(int i=0;i<leafCnt;i++) {
        dp[leafCnt][i] = triangle[leafCnt-1][i];
    }
    
    for(int i=leafCnt-1;i>=1;i--) {
        for(int j=0;j<leafCnt;j++) {
            dp[i][j] = max(dp[i+1][j]+triangle[i-1][j], dp[i+1][j+1]+triangle[i-1][j]);
        }
    }
    return dp[1][0];
}