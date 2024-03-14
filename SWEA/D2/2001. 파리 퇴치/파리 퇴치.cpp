
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int test_case;
	int T;
	
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		int n, m;
		cin >> n >> m;
		int table[16][16];

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> table[i][j];
			}
		}

		int result = 0;
		for (int i = 1; i <= n-(m-1); i++) {
			for (int j = 1; j <= n-(m-1); j++) {
				int total = 0;
				for (int k = 0; k < m; k++) {
					for (int t = 0; t < m; t++) {
						total += table[i + k][j + t];
					}
				}

				result = max(result, total);
			}
		}

		cout << "#" << test_case << " " << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}