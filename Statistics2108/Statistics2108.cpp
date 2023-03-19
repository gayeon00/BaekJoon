// Statistics2108.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <algorithm>
#include <cmath>
using namespace std;

double arithmeticMean(vector<int>& numbers) {
	int sum = 0;
	for (auto i : numbers) {
		sum += i;
	}
	int roundNum = round((double)sum / numbers.size());
	return (roundNum==0?0:roundNum);
}

int centerNumber(vector<int>& numbers) {
	sort(numbers.begin(), numbers.end());
	return numbers[numbers.size() / 2];
}

int mostFrequentNumber(array<int,8001>& countNumbers) {
	auto maxIndex = max_element(countNumbers.begin(), countNumbers.end());
	vector<int> mostFrequentNumbers;
	for (int i = 0; i < countNumbers.size(); i++) {
		if (countNumbers[i] == *maxIndex) {
			mostFrequentNumbers.push_back(i - 4000);
		}
	}
	return mostFrequentNumbers.size()==1?mostFrequentNumbers.front():*(mostFrequentNumbers.begin()+1);
	
}

int rangeBetMaxMin(vector<int>& numbers) {
	return numbers.back() - numbers.front();
}

int main() {
	int N;
	cin >> N;

	vector<int> numbers;
	int tmp;
	array<int, 8001> countNumbers = { 0 };
	while (N--) {
		cin >> tmp;
		numbers.push_back(tmp);
		countNumbers[tmp + 4000]++;
	}

	cout << arithmeticMean(numbers) << '\n';
	cout << centerNumber(numbers) << '\n';
	cout << mostFrequentNumber(countNumbers) << '\n';
	cout << rangeBetMaxMin(numbers) << '\n';

}
