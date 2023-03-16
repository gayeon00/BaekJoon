// Word1157.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

string word;
char ans;

void read_data() {
	cin >> word;
}


void solve() {
	array<int, 26> alphabet = { 0 };
	for (char& i : word) { //복사하는 듯?
		if (i >= 'a') alphabet[i - 'a']++;
		else alphabet[i - 'A']++;
	}

	
	int max = 0;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == max) ans = '?';
		else if (alphabet[i] > max) {
			max = alphabet[i];
			ans = 'A' + i;
		}
	}
}

void print_data() {
	cout << ans;
}

int main() {
	read_data();
	solve();
	print_data();
}
