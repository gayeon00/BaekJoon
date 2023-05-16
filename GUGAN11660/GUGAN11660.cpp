// GUGAN11660.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int S[1026][1026] = { 0 };

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;
			S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + tmp;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << S[c][d] - S[a - 1][d] - S[c][b - 1] + S[a - 1][b - 1]<<'\n';
	}
}
