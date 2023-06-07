#include <iostream>
using namespace std;

int main() {
	int start_index = 1, end_index = 1;
	int sum = 1, count = 1;
	int N;

	cin >> N;

	while (end_index != N) {
		if (sum == N) {
			count++;
			end_index++;
			sum += end_index;
		} else if (sum < N) {
			end_index++;
			sum += end_index;
		} else {
			sum -= start_index;
			start_index++;
		}
	}

	cout << count;
}