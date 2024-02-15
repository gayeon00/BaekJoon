#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> strs;
    for(auto i: numbers) {
        strs.push_back(to_string(i));
    }
    
    sort(strs.begin(), strs.end(), compare);
    
    for(auto i: strs) {
        answer += i;
    }
    
    if(answer[0] == '0') {
        answer = "0";
    }
    
    return answer;
}