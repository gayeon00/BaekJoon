#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//arr중 h번 이상 인용된 논문의 갯수 구하기
int countOverH(int h, vector<int>& arr) {
    int total = 0;
    for(int i: arr) {
        if(i>=h) {
            total++;
        }
    }
    
    return total;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());
    for(int i=citations[0];i>=0;i--) {
        int cnt = countOverH(i, citations);
        if(cnt >= i) {
            answer = i;
            break;
        }
    }
    
    return answer;
}