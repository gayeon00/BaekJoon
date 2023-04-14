#include <iostream>
using namespace std;

int main() {
	/*
	i번째 부터 j번째 수까지 합 구하기
	gugan(i,j) = until(j)-sum(i-1)
	*/
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int until[100001] = {};
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		until[i] = until[i - 1] + tmp;
	}

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		cout << until[y] - until[x-1] << '\n';
	}
}