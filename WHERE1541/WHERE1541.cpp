#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string& s, const char delimeter) {
	stringstream ss(s);
	string single;
	vector<string> ps;

	while (getline(ss, single, delimeter)) {
		ps.push_back(single);
	}

	return ps;
}

int mySum(string ex) {
	int sum = 0;
	vector<string> vs = split(ex, '+');
	for (string s : vs) {
		sum += stoi(s);
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string ex;
	cin >> ex;

	vector<string> splitted = split(ex, '-');

	int result=0;
	for (int i = 0; i < splitted.size(); i++) {
		int sum = mySum(splitted[i]);

		if (i == 0) {
			result += sum;
		} else {
			result -= sum;
		}
	}

	cout << result;
}