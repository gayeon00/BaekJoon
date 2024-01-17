#include <string>
#include <vector>

using namespace std;


//'A'는 17번
int solution(string name) {
    int answer = 0;
    
    int len = name.length();

    // 상하 이동 최소 횟수 계산
    for (int i = 0; i < len; i++) {
        int up = name[i] - 'A';
        int down = 'Z' - name[i] + 1;
        answer += (up < down) ? up : down;
    }
    
    int move = len - 1;
    for(int i = 0; i < len; i++) {
        int next = i + 1;//오른 쪽 다음
        while(next < len && name[next]=='A') { //A가 아닌 곳 까지 도달
            next++;
            
        }
        //next는 이제 A가 아닌 놈이 있는 곳
        //여기까지 어떻게 오는게 제일 빠른지
        move = min(move, i+len-next+min(i,len-next));
    }
    
    answer += move;
    
    return answer;
}