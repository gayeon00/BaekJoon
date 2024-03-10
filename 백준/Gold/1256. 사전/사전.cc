#include <iostream>

using namespace std;

int n, m, k;
int D[202][202] = { 0 };
int main() {
	cin >> n >> m >> k;

	//D[i][j] 채우기
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				D[i][j] = 1;
			} else {
				D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
				if (D[i][j] > 1000000000) {
					D[i][j] = 1000000001;
				}
			}
		}
	}
	//만들 수 있는 순열의 수가 구하려는 k보다 작으면
	if (D[n + m][m] < k) {
		cout << "-1";
	} else {
		while (!(n == 0 && m == 0)) {
			if (D[n + m - 1][m] >= k) {
				cout << "a";
				n--;
			} else {
				cout << "z";
				k -= D[n + m - 1][m];
				m--;
			}
		}
	}
} 