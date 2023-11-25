#include <string>
#include <vector>
#define MX 999999999
using namespace std;

vector<vector<int>> dp(1000, vector<int>(1000,MX));

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0, alp_mx = 0, cop_mx = 0;
    for(int i = 0;i < problems.size(); i++) {
        alp_mx = max(alp_mx, problems[i][0]);
        cop_mx = max(cop_mx, problems[i][1]);
    }
    
    //예외 처리
    alp = min(alp, alp_mx), cop = min(cop, cop_mx);
    dp[alp][cop] = 0;
    int x_idx, y_idx;
    for(int i = alp; i <= alp_mx; i++) {
        for(int j = cop; j <= cop_mx; j++) {
            //예외처리
            x_idx = min(i + 1, alp_mx), y_idx = min(j + 1, cop_mx);
            
            //case 1. 알고력 증가
            dp[x_idx][j] = min(dp[x_idx][j], dp[i][j] + 1);
            //case 2. 코딩력 증가
            dp[i][y_idx] = min(dp[i][y_idx], dp[i][j] + 1);
            //문제 풀기
            for(int k = 0; k < problems.size(); k++) {
                int alp_req = problems[k][0], cop_req = problems[k][1];
                int alp_rwd = problems[k][2], cop_rwd = problems[k][3];
                int cost = problems[k][4];
                
                //아직 풀지 못하는 문제
                if(i < alp_req || j < cop_req) continue;
                
                //예외처리
                x_idx = min(i + alp_rwd, alp_mx), y_idx = min(j + cop_rwd, cop_mx);
                dp[x_idx][y_idx] = min(dp[x_idx][y_idx], dp[i][j] + cost);
            }
        }
    }
    
    return answer = dp[alp_mx][cop_mx];
    
    
}