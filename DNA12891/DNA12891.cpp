#include <iostream>
#include <string>
using namespace std;

//A,C,G,T 필요 수
int require[4];
//돌아보면서 A, C,G,T 각각 갯수가 만족하는지 체크
int check[4];
//필요수 == 체크 인 알파벳
int satisfy_count = 0;

void Add(char c) {
	switch (c) {
	case 'A':
		check[0]++;
		if (check[0] == require[0]) satisfy_count++;
		break;
	case'C':
		check[1]++;
		if (check[1] == require[1]) satisfy_count++;
		break;
	case'G':
		check[2]++;
		if (check[2] == require[2]) satisfy_count++;
		break;
	case'T':
		check[3]++;
		if (check[3] == require[3]) satisfy_count++;
		break;
	default:
		break;
	}
}

void Remove(char c) {
	switch (c) {
	case 'A':
		if (check[0] == require[0]) satisfy_count--;
		check[0]--;
		break;
	case'C':
		if (check[1] == require[1]) satisfy_count--;
		check[1]--;
		break;
	case'G':
		if (check[2] == require[2]) satisfy_count--;
		check[2]--;
		break;
	case'T':
		if (check[3] == require[3]) satisfy_count--;
		check[3]--;
		break;
	default:
		break;
	}
}
int main() {
	int S, P;
	cin >> S >> P;

	string str;
	cin >> str;

	int result = 0;

	for (int i = 0; i < 4; i++) {
		cin >> require[i];
		if (require[i] == 0) satisfy_count++;
	}


	
	//str의 맨앞 P개 A,C,G,T갯수 체크
	for (int i = 0; i < P; i++) {
		Add(str[i]);
	}

	if (satisfy_count == 4) {
		result++;
	}

	for (int j = P; j < S; j++) {
		int i = j - P;
		Add(str[j]);
		Remove(str[i]);

		if (satisfy_count == 4) result++;
	}

	cout << result;
}