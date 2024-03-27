#include <string>
#include <vector>
#include <stack>

using namespace std;

//s를 i만큼 왼쪽으로 회전
string rotate(string s, int num) {
    string result;
    for(int i = num;i<s.size();i++) {
        result.push_back(s[i]);
    }
    for(int i=0;i<num;i++) {
        result.push_back(s[i]);
    }
    return result;
}

bool validate(string s) {
    stack<char> st;
    for(char ch: s) {
        if(ch=='('||ch=='['||ch=='{') {
            st.push(ch);
        } else if(ch==')') {
            if(!st.empty() && st.top()=='(') {
                st.pop();
            } else {
                st.push(ch);
            }
        } else if(ch==']') {
            if(!st.empty() && st.top()=='[') {
                st.pop();
            } else {
                st.push(ch);
            }
        } else if(ch=='}') {
            if(!st.empty() && st.top()=='{') {
                st.pop();
            } else {
                st.push(ch);
            }
        }
    }
    
    if(!st.empty()) {
        return false;
    } else {
        return true;
    }
}

int solution(string s) {
    int answer = 0;
    
    for(int i=0;i<s.size();i++) {
        string after = rotate(s,i);
        if(validate(after)) {
            answer++;
        }
    }
    
    return answer;
}