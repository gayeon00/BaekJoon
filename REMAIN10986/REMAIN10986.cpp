#include <iostream>
#include <vector>
using namespace std;

//구간합 배열
vector<long> S;

//구간합 % M 배열
vector<long> remain;

//0~M-1나머지애 대해 갯수
vector<long> C;

long cnt = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	S.resize(N + 1, 0);
	remain.resize(N + 1, 0);
	C.resize(M, 0);

	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		S[i] = S[i - 1] + tmp;

		remain[i] = S[i] % M;

		if (remain[i] == 0) cnt++;

		C[remain[i]]++;
	}
	
	for (int i = 0; i < M; i++) {
		cnt += C[i] * (C[i] - 1) / 2;
	}

	cout << cnt;




}