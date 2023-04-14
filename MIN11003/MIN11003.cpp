#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	/*
	슬라이딩 윈도우!
	덱에 {인덱스, 숫자}로 집어 넣기
	덱에 넣을 때, 들어가는 숫자랑 맨 뒤에 있는 숫자 비교해서
	맨 뒤에 있는 숫자가 더크다면 빼주기
	=> 오름차순 정렬가능! => 최솟값 구하는 거니까 나중에 그냥 맨 앞값 가져오면 됨!
	그리고 맨 뒤에 인덱스 - 맨 앞 인덱스 < L이어야함! (윈도우 크기 때문)
	*/
	int N, L;
	cin >> N >> L;

	deque<pair<int,int>> dq;
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		while (dq.size() && dq.back().second > tmp) {
			dq.pop_back();
		}
		dq.push_back({ i,tmp });
		if (dq.back().first - dq.front().first >= L) {
			dq.pop_front();
		}

		cout << dq.front().second << " ";
	}
	
}