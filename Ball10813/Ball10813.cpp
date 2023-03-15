// Ball10813.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void read_data();
void print_data();

int n, m;
vector<int> numbers;

int main() {
	read_data();
	print_data();
}

void read_data() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		numbers.push_back(i + 1);
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		swap(numbers[a - 1], numbers[b - 1]);
	}
}

void print_data() {
	for (auto i = numbers.begin(); i < numbers.end(); i++) {
		cout << *i << " ";
	}
}
