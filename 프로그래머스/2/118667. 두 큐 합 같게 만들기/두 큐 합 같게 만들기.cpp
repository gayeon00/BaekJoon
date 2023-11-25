#include <string>
#include <vector>
#include <queue>

using namespace std;

long total(queue<int> q) {
    long tot = 0;
    while(!q.empty()) {
        tot += q.front();
        q.pop();
    }
    return tot;
}

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> q1;
    for(int i: queue1) {
        q1.push(i);
    }
    
    queue<int> q2;
    for(int i: queue2) {
        q2.push(i);
    }
    
    int answer = 0;
    long total1 = total(q1);
    long total2 = total(q2);
    if((total1+total2)%2==1) return -1;
    
    while(true) {
        if(answer >= 2*(q1.size()+q2.size())) {
            answer = -1;
            break;
        }
        if(q1.empty() || q2.empty()) {
            answer = -1;
            break;
        }
        
        if(total1 > total2) {
            q2.push(q1.front());
            total1 -= q1.front();
            total2 += q1.front();
            q1.pop();
            answer++;
        } else if(total1 < total2){
            q1.push(q2.front());
            total2 -= q2.front();
            total1 += q2.front();
            q2.pop();
            answer++;
        } else {
            break;
        }
    }
    
    return answer;
}