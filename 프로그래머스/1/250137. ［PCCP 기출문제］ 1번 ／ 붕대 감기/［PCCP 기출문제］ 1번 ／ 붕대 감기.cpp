#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int tmp = health;
    
    
    
    for(int i = 0; i < attacks.size() - 1; i++) {
        vector<int> attack = attacks[i];
        tmp -= attack[1];
        if(tmp <= 0) return -1;
        
        vector<int> next_attack = attacks[i + 1];
        int dur = 0;
        for(int j = attack[0] + 1; j < next_attack[0]; j++ ) {
            tmp += bandage[1];
            dur++;
            if(dur == bandage[0]) { //한번도 안멈춰지고 구현했다면
                tmp += bandage[2];
                dur = 0;
            }
            if(tmp > health) {
                tmp = health;
            }
        }
        
    }
    tmp -= attacks[attacks.size()-1][1];
    if(tmp <= 0) return -1;
    return tmp;
}