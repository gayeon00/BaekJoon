#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

//v 숫자 중 num 이상인 숫자의 갯수
int count_larger(vector<int>& v, int num) {
    int result = 0;
    for(auto i: v) {
        if(i>=num) result++;
    }
    return result;
}

int solution(vector<int> citations) {
    int answer = -1;
    
    sort(citations.begin(), citations.end());
    
    for(int i = 0; i <= citations.back(); i++) {
        if(count_larger(citations, i) >= i) {
            answer = max(answer, i);
        }
    }
    
    return answer;
    //[10,11] return 2가 돼야함
}