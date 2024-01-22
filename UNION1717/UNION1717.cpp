#include <iostream>

using namespace std;

int parents[1000001];

int find(int a) {
	if (parents[a] == a) {
		return a;
	}

	return parents[a] = find(parents[a]);
}

void u(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		parents[b] = a;
	}
}

void checkSame(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		cout << "NO" << '\n'; 
	} else {
		cout << "YES" << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parents[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 0) {
			u(a, b);
		} else {
			checkSame(a, b);
		}
	}
}