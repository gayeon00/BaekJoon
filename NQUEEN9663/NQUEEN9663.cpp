#include <iostream>

using namespace std;

int N, cnt = 0;
int arr[15];

bool isPossible(int column) {
	for (int i = 0; i < N; i++) {
		//동일한 행에 놓은 열이 있는지, 대각선 상에 놓은 열이 있는지 검사
		if (arr[column] == arr[i] || abs(column - arr[column]) == abs(i - arr[i])) {
			return false;
		}
	}
}

void DFS(int column) {
	if (column == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		arr[column] = i;
		//i행에 놓았을 때, 그 열은 가능한가!
		if(isPossible(column)) DFS(column + 1);
		//안되면 그냥 넘어가서 다음 행 탐색하는 거지
	}

}


int main() {
	cin >> N;

	DFS(0);
	cout << cnt << '\n';

	
}