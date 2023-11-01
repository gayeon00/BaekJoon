#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    vector<long long> stack;
    int start = 1;
    
    for(int station: stations) {
        stack.push_back(station-w-start);
        start = station+w+1;
    }
    
    stack.push_back(n+1-start);
    
    
    for(auto count: stack) {
        if(count <= 0) {
            continue;
        }
        
        if(count%(2*w+1)!=0) {
            answer += count/(2*w+1)+1;
        } else {
            answer += count/(2*w+1);
        }
    }

    return answer;
}