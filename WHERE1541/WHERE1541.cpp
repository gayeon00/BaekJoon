#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> N;
vector<char> C;

vector<string> splice(string str, char chracter) {
	vector<string> result;
	string tmp;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '-') {
			result.push_back(tmp);
			tmp.clear();
		} else {
			tmp.push_back(str[i]);
		}
	}
	result.push_back(tmp);

	return result;
}

int expression_to_int(string expression) {
	int num = 0, result = 0;
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] == '+') {
			result += num;
			num = 0;
		} else {
			num = num * 10 + (expression[i]-'0');
		}
	}
	result += num;
	return result;
}

int main() {
	string str;
	cin >> str;

	//-를 기준으로 나누기
	vector<string> spliced = splice(str, '-');
	//한 덩이 계산하기
	int result = expression_to_int(spliced[0]);
	//cout << result << '\n';
	for (int i = 1; i < spliced.size(); i++) {
		int tmp = expression_to_int(spliced[i]);
		//cout << tmp << '\n';
		result -= tmp;
	}

	cout << result;
}