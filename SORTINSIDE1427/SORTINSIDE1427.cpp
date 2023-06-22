// SORTINSIDE1427.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    string str;
    cin >> str;

    vector<int> A(str.size(), 0);
    for (int i = 0; i < str.size(); i++) {
        A[i] = stoi(str.substr(i, 1));
    }

    for (int i = 0; i < str.size(); i++) {
        int Max = i;
        //최댓값의 인덱스 찾기
        for (int j = i + 1; j < str.size(); j++) {
            if (A[j] > A[Max]) Max = j;
        }
        //최댓값이랑 지금 숫자랑 비교해서 swap
        if (A[i] < A[Max]) {
            //swap하기
            int tmp = A[i];
            A[i] = A[Max];
            A[Max] = tmp;
        }
    }

    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
    }
}   
