#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;

    vector<int> dp(sticker.size());
    
    if(sticker.size()==1){
        return sticker[0];
    }
    
    //첫번째꺼 뜯음
    dp[0] = sticker[0];
    dp[1] = dp[0];
    for(int i = 2; i < sticker.size() - 1; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
    }
    dp[sticker.size()-1] = dp[sticker.size()-2];
    answer = *max_element(dp.begin(), dp.end());
    
    //첫번째꺼 안뜯음
    dp[0] = 0;
    for(int i = 1; i < sticker.size(); i++) {
        dp[i] = max(dp[i-1], dp[i-2]+sticker[i]);
    }
    answer = max(answer, *max_element(dp.begin(), dp.end()));

    return answer;
}