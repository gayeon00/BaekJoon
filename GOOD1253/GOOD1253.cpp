#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	/*
	수를 배열로 나타내고,
	맨 앞을 가리키는 포인터1, 타겟 숫자를 가리키는 포인터2
	while(포인터1이 포인터2보다 앞에 있을 동안){
		if(포인터1+포인터2가 타겟이면) {
			count++;
			while문 나가기!
		}
	}
	*/
	int N;
	cin >> N;

	int numbers[2000];
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}
	
	sort(numbers, numbers+N);

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int a = 0, b = N - 1;
		while (a < b) {
			if (numbers[a] + numbers[b] == numbers[i]) {
				if (a != i && b != i) {
					cnt++;
					break;
				} else if (a == i) {
					a++;
				} else if (b == i) {
					b--;
				}
			} else if (numbers[a] + numbers[b] > numbers[i]) {
				b--;
			} else {
				a++;
			}
		}
	}

	cout << cnt;


}