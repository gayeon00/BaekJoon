#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	//N그자체 포함
	int result = 1;

	int i = 1, j = 1;
	int sum = 1;
	while (j != N) {
		if (sum < N) {
			j++;
			sum += j;
		} else if (sum > N) {
			sum -= i;
			i++;
		} else {
			j++;
			sum += j;
			result++;
		}
	}

	cout << result;


}