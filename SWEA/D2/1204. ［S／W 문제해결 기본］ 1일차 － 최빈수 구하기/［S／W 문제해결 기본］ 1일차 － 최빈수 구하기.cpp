#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;

		int cnt_score[101] = { 0 };
		for (int i = 0; i < 1000; i++) {
			int score;
			cin >> score;
			cnt_score[score]++;
		}

		int max_cnt = 0;
		int result = 0;
		for (int i = 100; i >= 0;i--) {
			if (max_cnt < cnt_score[i]) {
				max_cnt = cnt_score[i];
				result = i;
			}
		}

		cout << "#" << n  << " " << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}