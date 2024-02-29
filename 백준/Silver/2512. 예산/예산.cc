#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> budgets(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> budgets[i];
	}

	long long m;
	cin >> m;

	sort(budgets.begin(), budgets.end());

	int answer = 0;
	int tmp = budgets.back();
	while (tmp > 0) {
		long long result = 0;
		for (int i = 0; i < n; i++) {
			if (budgets[i] <= tmp) {
				result += budgets[i];
			} else {
				result += tmp;
			}
		}

		if (result <= m) {
			answer = tmp;
			break;
		} else {
			tmp--;
		}
	}

	cout << answer;

	
	return 0;
}