// STACK1874.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
//꺼내야될 숫자 tmp가 stack의 top보다 크거나 같은 수여야 stack의 성질을 만족함
int main()
{
    int N;
    cin >> N;

    vector<int> v;
    vector<char> result;
    //1부터 N까지의 수열 숫자
    int j = 1;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        //stack이 비었으면 수열 숫자 넣어주기
        if (v.size() == 0) {
            v.push_back(j++);
            result.push_back('+');
        }

        //"stack의 top"이 "꺼내야될 숫자"보다 크거나 같을 때까지 수열 숫자 넣기
        while (v.back() < tmp) {
            v.push_back(j++);
            result.push_back('+');
        }

        //"stack의 top"이 "꺼내야될 숫자"보다 크거나 같아지면
        //같아야만 pop할 수 있음
        if (v.back() == tmp) {
            v.pop_back();
            result.push_back('-');
            //더 크다면 만들 수 없는 수임!
        } else {
            cout << "NO";
            return;
        }
    }

    for (auto i : result) {
        cout << i << '\n';
    }
}
