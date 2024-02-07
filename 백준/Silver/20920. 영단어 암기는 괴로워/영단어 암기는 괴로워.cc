// Voca20920.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<string, int> word_counts;

bool comp(string a, string b) {
    if (word_counts[a] == word_counts[b]) {
        if (a.length() == b.length()) {
            return a < b;
        } else {
            return a.length() > b.length();
        }
    } else {
        return word_counts[a] > word_counts[b];
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        if(word.length() >= m) word_counts[word]++;
    }

    vector<string> result;
    //단어장에 집어넣기
    for (auto i : word_counts) {
        result.push_back(i.first);
    }

    sort(result.begin(), result.end(), comp);

    for (auto i : result) {
        cout << i << '\n';
    }

    return 0;

}
