// Nudge01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <sstream>
#include <string.h>

using namespace std;

vector<string> split(const string& text) {
    vector<string> result;
    string tmp;
    for (auto ch : text) {
        if (ch == ' ') {
            result.push_back(tmp);
            tmp = "";
        } else {
            tmp.push_back(ch);
        }
    }
    result.push_back(tmp);
    return result;
}

vector<string> formatText(const string& text, int width) {
    vector<string> result;
    //띄어쓰기 기준으로 자름 (한 단어씩)
    vector<string> splitted = split(text);
    string tmp = "*  ";

    // Add top border
    result.push_back(string(width+2, '*'));
    for (auto str : splitted) {
        if (str.find("!") != string::npos || str.find(".") != string::npos || str.find("?") != string::npos) {
            if (tmp.size() + str.size() - 1 <= width) {
                tmp.append(str);
                //공백 채우기
                tmp.append(string(width - tmp.size() + 1, ' '));
                //* 닫기
                tmp.push_back('*');
                result.push_back(tmp);

                tmp = "*  ";
            } else {
                //공백 채우기
                tmp.append(string(width - tmp.size() + 1, ' '));
                //* 닫기
                tmp.push_back('*');
                result.push_back(tmp);

                //새 줄
                tmp = "*";
                tmp.append(str);
                //공백 채우기
                tmp.append(string(width - tmp.size() + 1, ' '));
                //* 닫기
                tmp.push_back('*');
                result.push_back(tmp);

                tmp = "*  ";
            }
            
        } else {
            if (tmp.size() + str.size() - 1 < width) {
                tmp.append(str+" ");
                
            } else if (tmp.size() + str.size() - 1 == width) {
                tmp.append(str+"*");
                result.push_back(tmp);

                tmp = "*";
            }
            else {
                //공백 채우기
                tmp.append(string(width - tmp.size() + 1, ' '));
                //* 닫기
                tmp.push_back('*');
                result.push_back(tmp);

                tmp = "*";
                tmp.append(str + " ");
            }
            
        }
    }
    

    // Add bottom border
    result.push_back(string(width+2, '*'));

    return result;
}

int main() {
    string inputText = "Hi! This is sentence one. Please format this text according to the rules. Can you do that? Let's see!";
    int width = 20;

    vector<string> result = formatText(inputText, width);

    for (const auto& line : result) {
        cout << line << endl;
    }

    return 0;
}
