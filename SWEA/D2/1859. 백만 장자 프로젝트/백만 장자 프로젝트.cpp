#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;

		vector<int> A;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			A.push_back(num);
		}
		long result = 0; 
		int s = n - 1, e = n - 1;
		while (e >= 0) {
			while (s >= 0 && A[s] <= A[e]) {
				s--;
			}

			
			for (int i = s + 1; i < e; i++) {
				result += (A[e] - A[i]);
			}
			e = s;
		}
		
		cout << "#" << test_case << " " << result << '\n';
 		
 	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}