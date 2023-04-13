#include <iostream>
#include <queue>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>

using namespace std;

int sansul(vector<int>& numbers, int N) {
	double result = 0;
	for (auto i = 0; i <N ; i++) {
		result += numbers[i];
	}
	result = round(result / N);
	return result == 0 ? 0 : result;
}

int joongang(vector<int>& numbers, int N) {
	return numbers[N / 2];
}

int choibin(array<int, 8001>& countNumbers, int N) {
	auto maxIter = max_element(countNumbers.begin(), countNumbers.end());
	vector<int> choibinNumbers;
	for (int i = 0; i < 8001; i++) {
		if (countNumbers[i] == *maxIter) {
			choibinNumbers.push_back(i - 4000);
		}
	}
	return choibinNumbers.size() == 1 ? choibinNumbers[0] : choibinNumbers[1];
}

int range(vector<int>& numbers, int N) {
	return numbers[N - 1] - numbers[0];
}


int main() {
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> q;
	array<int, 8001> countNumbers = { 0 };
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		q.push(tmp);
		countNumbers[tmp + 4000]++;
	}

	vector<int> numbers;
	while (!q.empty()) {
		numbers.push_back(q.top());
		q.pop();
	}

	cout << sansul(numbers, N) << '\n';
	cout << joongang(numbers, N) << '\n';
	cout << choibin(countNumbers, N) << '\n';
	cout << range(numbers, N) << '\n';

}