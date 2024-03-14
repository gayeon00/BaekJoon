
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
	int test_case;
	for (test_case = 1; test_case <= 10; ++test_case) {
		int n;
		cin >> n;

		vector<int> buildings;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			buildings.push_back(tmp);
		}

		long result = 0;
		for (int i = 2; i <= n - 3; i++) {
			int tall = 0;
			tall = max(tall, buildings[i - 2]);
			tall = max(tall, buildings[i - 1]);
			tall = max(tall, buildings[i + 1]);
			tall = max(tall, buildings[i + 2]);

			if (tall < buildings[i]) {
				result += buildings[i] - tall;
			}
		}

		cout << "#" << test_case << " " << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}