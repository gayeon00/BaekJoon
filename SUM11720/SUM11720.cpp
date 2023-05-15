// SUM11720.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    long N;
    string num;
    cin >> N >> num;

    long result = 0;
    for (int i = 0; i < N; i++) {
        result += num[i] - '0';
    }

    cout << result;

}
