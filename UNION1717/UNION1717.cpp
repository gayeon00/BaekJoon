#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;

int find(int a) {
	if (parents[a] == a) return a;

	return parents[a] = find(parents[a]);
}

void unionfunc(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		parents[b] = a;
	}
}

void checkSame(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
}

int main() {
	ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	parents.resize(n + 1);

	//대표노드 자기 자신으로 초기화
	for (int i = 0; i <= n; i++) {
		parents[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int flag, a, b;
		cin >> flag >> a >> b;

		if (flag) checkSame(a, b);
		else	  unionfunc(a, b);
	}
}