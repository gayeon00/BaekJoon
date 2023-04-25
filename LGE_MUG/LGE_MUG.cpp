// LGE_MUG.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> pll;




int main() {
    int N;
    priority_queue<pll> q;
    stack<long long> st;
    cin >> N;
    //top이 제일 먼 것
    for (int i = 0; i < N; i++) {
        long x, y;
        cin >> x >> y;
        q.push({ x,y });
    }

    long long result = 0;
    st.push(q.top().second);
    q.pop();
    result += st.top();
    
    while (!q.empty()) {
        while (!st.empty() && st.top() > q.top().second) {
            st.pop();
        }
        if (st.empty()) result += q.top().second;
        else result += st.top();
       
        st.push(q.top().second);
        q.pop();
        
    }

    cout << result;
}
