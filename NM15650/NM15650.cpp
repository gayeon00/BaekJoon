// NM15650.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 8;
int N, M;
int arr[MAX];
bool is_used[MAX + 1];


void backtrack(int k) {
	if (k == M) {
		bool flag = true;
		for (int i = 0; i < M-1; i++) {
			if (arr[i]>arr[i + 1]) {
				flag = false;
			}
		}
		if (flag) {
			for (int i = 0; i < M; i++) {
				cout << arr[i] << ' ';
			}
			cout << '\n';
		}
		return;
	}

	for (int i = 1; i <= N; i++) {
		arr[k] = i;
		backtrack(k + 1);
	}
}

int main(){
	cin >> N >> M;
	backtrack(0);
}
