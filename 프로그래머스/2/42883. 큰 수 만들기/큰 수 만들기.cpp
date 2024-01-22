#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int max_idx = -1;
    int max = 0;
    
    //남길 number.size()-k개 구하기
    for (int i = 0; i < number.size() - k; i++) {
        max = 0;
        int start = max_idx+1;
        int end;
        
        if(k+i+1 > number.size()) {
            end = number.size();
        } else {
            end = k+i+1;
        }
        
        for(int j = start; j < end; j++) {
            if(number[j] > max) {
                max_idx= j;
                max= number[j];
            }
        }
        answer += max;
    }
    return answer;
}