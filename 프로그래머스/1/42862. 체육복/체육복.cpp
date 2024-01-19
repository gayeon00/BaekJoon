#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> students(n+1, 1);
    for(auto i: lost) {
        students[i]--;
    }
    
    for(auto i: reserve) {
        students[i]++;
    }
    
    for(int i = 1; i <= n; i++) {
        if(students[i]==0) {
            if(students[i-1] ==2) {
                students[i-1]--;
                students[i]++;
            } else if(students[i+1]==2) {
                students[i+1]--;
                students[i]++;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(students[i]!=0) {
            answer++;
        }
    }
    
    return answer;
}