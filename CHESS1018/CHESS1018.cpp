#include <iostream>
#include <string>
using namespace std;

string wb = "WBWBWBWB";
string bw = "BWBWBWBW";

int N, M;
string board[50];

void read_data() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
}

int countWhiteFirst(char tmp[][8]) {
	int diff = 0;
	string full[8] = { wb,bw,wb,bw,wb,bw,wb,bw };

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tmp[i][j] != full[i][j]) diff++;
		}
	}
	return diff;
}

int countBlackFirst(char tmp[][8]) {
	int diff = 0;
	string full[8] = { bw,wb,bw,wb,bw,wb,bw,wb };

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tmp[i][j] != full[i][j]) diff++;
		}
	}
	return diff;
}

void solve() {
	int myMin = 64;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			char tmp[8][8];

			for (int k = 0; k < 8; k++) {
				for (int t = 0; t < 8; t++) {
					tmp[k][t] = board[i + k][j + t];
				}
			}
			myMin = min(myMin, min(countWhiteFirst(tmp), countBlackFirst(tmp)));
		}
	}

	cout << myMin;
}

int main() {
	read_data();
	solve();
}