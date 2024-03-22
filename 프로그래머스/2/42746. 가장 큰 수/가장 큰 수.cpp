#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {
    return b+a<a+b;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNumbers;
    for(int num: numbers) {
        strNumbers.push_back(to_string(num));
    }
    
    sort(strNumbers.begin(), strNumbers.end(), compare);
    
    if(strNumbers[0]=="0") {
        answer = "0";
    } else {
        for(string str: strNumbers) {
            answer.append(str);
        }
    }
    
    
    return answer;
}