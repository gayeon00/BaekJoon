#include <iostream>

using namespace std;

int N;
int numbers[11];
int op[4];
int maxNum = -1000000001;
int minNum = 1000000001;

void getAnswer(int result, int index) {
	if (index == N) {
		if (result > maxNum) maxNum = result;
		if (result < minNum) minNum = result;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;
			switch (i) {
			case 0:
				getAnswer(result + numbers[index], index + 1);
				break;
			case 1:
				getAnswer(result - numbers[index], index + 1);
				break;
			case 2:
				getAnswer(result * numbers[index], index + 1);
				break;
			case 3:
				getAnswer(result / numbers[index], index + 1);
				break;
			default:
				break;
			}
			op[i]++;
		}
	}
}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	getAnswer(numbers[0], 1);
	cout << maxNum << '\n';
	cout << minNum;

}