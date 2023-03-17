// GroupWordChecker1316.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<string> words;
int numGroupWord=0;

void read_data() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		words.push_back(temp);
	}
}

bool isGroupWord(string word) {
	string checkedAlpahbet;
	for (auto character : word) {
		if (checkedAlpahbet.find(character) != string::npos
			&& checkedAlpahbet.find(character) != checkedAlpahbet.size() - 1) {
			//스택 안에 이미 존재하고 제일 최근에 넣어진게 아닐 경우 => 그룹단어가 아닌 경우!
			return false;
		} else if (checkedAlpahbet.find(character) != string::npos
			&& checkedAlpahbet.find(character) == checkedAlpahbet.size() - 1) {
			//스택 안에 이미 존재하는데, 바로 앞에 나온 경우
		} else {
			checkedAlpahbet.push_back(character);
		}
	}
	return true;
}

void solve() {
	for (auto word : words) {
		if (isGroupWord(word)) numGroupWord++;
	}
}



void print_data() {
	cout << numGroupWord;
}

int main(){
	read_data();
	solve();
	print_data();
}
