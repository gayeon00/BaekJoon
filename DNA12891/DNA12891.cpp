#include <iostream>
using namespace std;

int checkArr[4];
int myArr[4];
int checkSecret = 0;
void Add(char c);
void Remove(char c);

int main() {
	int S, P;
	cin >> S >> P;

	int result = 0;

	string A;
	cin >> A;

	for (int i = 0; i < 4; i++) {
		cin >> checkArr[i];
		if (checkArr[i] == 0) {
			checkSecret++;
		}
	}

	//초기상태. 문자열 0번째부터 P번째까지 알파벳 카운트를 더해줌
	for (int i = 0; i < P; i++) {
		Add(A[i]);
	}

	//초기상태가 조건을 만족하면 result++
	if (checkSecret == 4) {
		result++;
	}

	//슬라이딩 윈도우 처리
	//초기상태가 P-1번째까지 처리돼있으니까 P번째로 늘어나기
	for (int i = P; i < S; i++) {
		//앞 인덱스는 {마지막인덱스 - 길이} 해줌됨
		int j = i - P;
		//뒤 인덱스는 알파벳 카운트 더해주고
		Add(A[i]);
		//앞 인덱스는 알파벳 카운트 빼줌
		Remove(A[j]);


		//한번 하고 조건 만족하면 result++;
		if (checkSecret == 4) {
			result++;
		}
	}

	cout << result;
}

void Add(char c) {
	switch (c) {
	case 'A':
		myArr[0]++;
		if (myArr[0] == checkArr[0]) {
			checkSecret++;
		}
		break;
	case 'C':
		myArr[1]++;
		if (myArr[1] == checkArr[1]) {
			checkSecret++;
		}
		break;
	case 'G':
		myArr[2]++;
		if (myArr[2] == checkArr[2]) {
			checkSecret++;
		}
		break;
	case 'T':
		myArr[3]++;
		if (myArr[3] == checkArr[3]) {
			checkSecret++;
		}
		break;
	default:
		break;
	}
}

void Remove(char c) {
	switch (c) {
	case 'A':
		//빠질 놈이 조건을 만족하고 있었다면 갯수--
		if (myArr[0] == checkArr[0]) {
			checkSecret--;
		}
		//빼주기
		myArr[0]--;
		break;
	case 'C':
		if (myArr[1] == checkArr[1]) {
			checkSecret--;
		}
		myArr[1]--;
		break;
	case 'G':
		if (myArr[2] == checkArr[2]) {
			checkSecret--;
		}
		myArr[2]--;
		break;
	case 'T':
		
		if (myArr[3] == checkArr[3]) {
			checkSecret--;
		}
		myArr[3]--;
		break;
	default:
		break;
	}
}