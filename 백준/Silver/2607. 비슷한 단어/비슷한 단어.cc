#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	string str;
	cin >> str;
	int base[26] = { 0 };
	for (char ch : str) {
		base[ch - 'A']++;
	}

	int answer = 0;

	for (int i = 0; i < N - 1; i++) {
		string tmp;
		cin >> tmp;

		int cbase[26] = { 0 };
		copy(base, base + 26, cbase);

		int same = 0;
		for(char ch: tmp) {
			if (cbase[ch - 'A'] > 0) {
				same++;
				cbase[ch - 'A']--;
			}
		}

		if (str.size() == tmp.size()) {
			if (same == str.size() || same == str.size() - 1) {
				answer++;
			}
		} else if (str.size() == tmp.size() + 1 && same == tmp.size()) {
			answer++;
		} else if (tmp.size() == str.size() + 1 && same == str.size()) {
			answer++;
		}
	}

	cout << answer;

	return 0;
}