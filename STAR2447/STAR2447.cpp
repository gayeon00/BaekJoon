// STAR2447.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;
int N;

void star(int x, int y, int n, vector<vector<char>>& arr) {
	if (n == 1) {
		arr[x][y] = '*';
		return;
	}
	
	//x,y는 시작점 좌측 상단이 0,0
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				//가운데 뻥 빈부분
				continue;
			}
			//뻥 빈 부분이 아니라면 
			star(x + i * (n / 3), y + j * (n / 3), n / 3, arr);
		}
	}
}


int main()
{
	cin >> N;

	vector<vector<char>> arr(N, vector<char>(N, ' '));
	star(0, 0, N, arr);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}

}
