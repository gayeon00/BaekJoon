// Croatia2941.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <array>
#include <vector>

using namespace std;

string croatiaWord; //ddz=z=

void read_data() {
	cin >> croatiaWord;
}

void solve() {
	int count = 0;
	for (int i = 0; i < croatiaWord.length(); i++) {
		if (croatiaWord[i] == 'c') {
			if (croatiaWord[i + 1] == '=' || croatiaWord[i + 1] == '-') {
				i++;
			}

		} else if (croatiaWord[i] == 'd') {
			if (croatiaWord[i + 1] == 'z' && croatiaWord[i + 2] == '=') {
				i += 2;
			} else if (croatiaWord[i + 1] == '-') {
				i++;
			}

		} else if (croatiaWord[i] == 'l' || croatiaWord[i] == 'n') {
			if (croatiaWord[i + 1] == 'j') {
				i++;
			}
		} else if (croatiaWord[i] == 's' || croatiaWord[i] == 'z') {
			if (croatiaWord[i + 1] == '=') {
				i++;
			}
		}
		count++;
	}
	cout << count;
}

int main() {
	read_data();
	solve();
}
