#include <string>
#include <map>
#include <iostream>
using namespace std;

typedef pair<int,int> pii;
map<pair<pii,pii>, bool> visited;

int solution(string dirs) {
    int answer = 0;
    
    int start_x = 5;
    int start_y = 5;
    
    
    for(char dir: dirs) {
        int next_x = start_x;
        int next_y = start_y;
        
        if(dir == 'U') {
            if(start_x - 1 < 0) continue;
            start_x--;
        } else if(dir == 'D') {
            if(start_x + 1 >10) continue;
            start_x++;
        } else if(dir == 'R') {
            if(start_y + 1 > 10) continue;
            start_y++;
        } else {
            if(start_y - 1 < 0) continue;
            start_y--;
        }
        
        if(visited[{{start_x,start_y},{next_x, next_y}}]) {
            continue;
        }
        
        visited[{{start_x,start_y},{next_x, next_y}}] = true;
        visited[{{next_x, next_y},{start_x,start_y}}] = true;
        answer++;
    }
    return answer;
}