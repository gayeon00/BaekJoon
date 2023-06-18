// STACK1874.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;

    vector<int> v;
    vector<char> result;
    int j = 1;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        if (v.size() == 0) {
            v.push_back(j++);
            result.push_back('+');
        }
        if (v.back() > tmp) {

        }
        while (v.back() < tmp) {
            v.push_back(j++);
            result.push_back('+');
        }
        if (v.back() == tmp) {
            v.pop_back();
            result.push_back('-');
        } else {
            cout << "NO";
            return 0;
        }
    }

    for (auto i : result) {
        cout << i << '\n';
    }
}
