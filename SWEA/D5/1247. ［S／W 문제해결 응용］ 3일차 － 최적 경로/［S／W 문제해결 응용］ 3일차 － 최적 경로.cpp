
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main(int argc, char** argv) {
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		vector<pair<int, int>> nodes;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			nodes.push_back(make_pair(x, y));
		}
		sort(nodes.begin(), nodes.end());
		long result = LONG_MAX;
		do {
			long total = 0;
			int nx = sx, ny = sy;
			for (auto next : nodes) {
				total += (abs(nx - next.first) + abs(ny - next.second));
				nx = next.first, ny = next.second;
			}

			total += (abs(nx - ex) + abs(ny - ey));

			result = min(result, total);

		} while (next_permutation(nodes.begin(), nodes.end()));

		cout << "#" << test_case << " " << result << '\n';

	}
	return 0;
}