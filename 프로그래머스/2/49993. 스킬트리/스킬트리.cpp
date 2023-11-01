#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool isPossible(string skill, string tree) {
    string stack;
    
    int i = 0;
    for(;i < tree.size(); i++) {
        char ch = tree[i];
        
        if(skill.find(ch) == string::npos) {
            continue;
        }
        int ch_index = skill.find(ch);
        if((stack.size() == 0) && (ch_index == 0)) {
            stack.push_back(ch);
        } else if ((stack.size() != 0) && (ch_index != 0)){
            //ch가 skill중 하나라면 바로 내 앞의 skill이 stack의 top이어야함
            if(skill[ch_index - 1] == stack.back()) {
                stack.push_back(ch);
            } else {
                break;
            }
        } else {
            break;
        }
        
    }
    
    if(i == tree.size()){
        return true;
    } else {
        return false;
    }
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(string tree: skill_trees) {
        if(isPossible(skill, tree)) {
            answer++;
        }
    }
    
    return answer;
}