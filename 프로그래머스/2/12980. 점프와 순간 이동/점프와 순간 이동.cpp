#include <iostream>
using namespace std;

int findOddFromEven(int even) {
    int tmp = even;
    while(tmp%2==0) {
        tmp /=2;
    }
    
    return tmp;
}

int dp(int n) {
    if(n==1) {
        return 1;
    }
    
    if(n%2==0) {
        return dp(findOddFromEven(n));
    } else {
        return dp(n-1)+1;
    }
}

int solution(int n)
{
    
//     int dp[1000000001];
//     dp[1] = 1;
    
//     for(int i=2;i<=n;i++) {
//         if(i%2==0){
//             dp[i] = dp[findOddFromEven(i)];
//         } else {
//             dp[i] = dp[i-1] + 1;
//         }
//     }
    
    return dp(n);
}