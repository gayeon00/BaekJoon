#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	priority_queue<int> q;
	for (int i = 0; i < s.size(); i++) {
		q.push(stoi(s.substr(i, 1)));
	}

	while (!q.empty()) {
		cout << q.top();
		q.pop();
	}
}