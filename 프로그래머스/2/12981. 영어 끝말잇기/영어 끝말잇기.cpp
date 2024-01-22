#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    vector<string> check;
    int round = 0, i = 0;
    for(;i<words.size();i++) {
        if(i%n == 0) round++;
        
        //이미 말한 단어거나
        if(find(check.begin(), check.end(), words[i])!=check.end()
           //끝말잇기가 안되거나
          || (check.size() != 0) && (check.back().back() != words[i].front())
           //한글자이거나
          || words[i].size() <= 1
          ) {
            answer.push_back(i%n+1);
            answer.push_back(round);
            break;
        }
        
        check.push_back(words[i]);
    }
    if(i==words.size()){
        answer.push_back(0);
        answer.push_back(0);
    }
    

    return answer;
}