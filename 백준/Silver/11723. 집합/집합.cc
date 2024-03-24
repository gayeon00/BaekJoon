// SET11723.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M;
    cin >> M;

    vector<bool> s(21, false);
    for (int i = 0; i < M; i++) {
        string mode;
        cin >> mode;
        

        if (mode == "check") {
            int x;
            cin >> x;

            if (s[x]) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (mode == "add") {
            int x;
            cin >> x;
            s[x] = true;
            
        } else if (mode == "remove") {
            int x;
            cin >> x;
            s[x] = false;

        } else if (mode == "toggle") {
            int x;
            cin >> x;
            s[x] = !s[x];

        } else if (mode == "all") {
            for (int j = 1; j <= 20; j++) {
                s[j] = true;
            }


        } else if (mode == "empty") {
            for (int j = 1; j <= 20; j++) {
                s[j] = false;
            }

        }
    
    }
}
