// PIPE10799.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string pipes;
    cin >> pipes;

    stack<char> s;
    int count = 0;
    char before;
    for (char ch : pipes) {
        
        if (!s.empty() && s.top() == '(' && ch == ')') {
            s.pop();
            if (before == '(') {
                //레이저
                count += s.size();
            } else {
                //파이프
                count += 1;
            }
            
        } else {
            s.push(ch);
        }

        before = ch;
    }

    cout << count;
}
