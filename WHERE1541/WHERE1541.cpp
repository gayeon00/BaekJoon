// WHERE1541.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

//모르겠는디?
vector<string> split(string input, char delimeter) {
    vector<string> result;
    //string을 stringstream으로 바꿔주기
    stringstream mystream(input);
    string splitdata;

    //mystream를 splitdata에 넣겠다. delimeter 기준으로 쪼갠것을 
    while (getline(mystream, splitdata, delimeter)) {
        result.push_back(splitdata);
    }
    return result;
}

int mySum(string input) {
    vector<string> result = split(input, '+');
    int sum = 0;
    for (auto i : result) {
        sum += stoi(i);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string expression;
    cin >> expression;

    vector<string> splitted = split(expression, '-');
    int result = 0;

    for (int i = 0; i < splitted.size(); i++) {
        int sum = mySum(splitted[i]);

        if (i == 0) {
            result += sum;
        } else {
            result -= sum;
        }
    }
    cout << result;
}