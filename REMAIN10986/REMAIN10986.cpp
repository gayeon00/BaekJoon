// REMAIN10986.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

long long S[1000001] = { 0 };
long long C[1000001] = { 0 };

int main()
{
	long long N, M;
	cin >> N >> M;

	long long cnt = 0;
	long long remain[1000] = { 0 };

	for (int i = 1; i <= N; i++) {
		long long tmp;
		cin >> tmp;
		//구간합 배열
		S[i] = S[i - 1] + tmp;

		//M으로 나눈 나머지를 담은 배열
		C[i] = S[i] % M;
		//해당 나머지가 0이라면 바로 cnt증가
		if (C[i] == 0) cnt++;
		//암튼 0~M-1에 대한 나머지에 대해 몇개씩 나오는지 세기
		remain[C[i]]++;
	}

	for (int i = 0; i < M; i++) {
		//같은 나머지를 가지는 숫자들 중 2개 조합
		cnt += remain[i] * (remain[i] - 1) / 2;
	}

	cout << cnt;
}
