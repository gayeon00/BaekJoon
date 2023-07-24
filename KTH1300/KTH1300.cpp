// KTH1300.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
int main() {
	long N, K;
	cin >> N >> K;
	long start = 1, end = K;
	long ans = 0;
	
	//이분탐색 수행
	while (start <= end) {
		long middle = (start + end) / 2;
		long cnt = 0;

		for (int i = 1; i <= N; i++) {
			cnt += min(middle / i, N);
		}

		if (cnt < K) {
			start = middle + 1;
		} else {
			ans = middle;
			end = middle - 1;
		}
	}

	cout << ans;

}
