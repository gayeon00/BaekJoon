#include <iostream>
#include <vector>

using namespace std;

int S[21][21];
bool visited[22];
int N;
int myMin = 1000000000;

void DFS(int x, int index) // x는 카운트 수, pos는 다음 값
{
	if (index == N / 2) // 카운트수가 정원의 1/2이 됐을 때 능력치합 계산
	{
		//visited가 true인놈, false인 놈으로 나눌 수 있음!!
		int start = 0, link = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visited[i] && visited[j]) start += S[i][j];
				if (!visited[i] && !visited[j]) link += S[i][j];
			}
		}
		int tmp = abs(start - link);
		if (tmp < myMin) myMin = tmp;
	}

	for (int i = x; i <= N; i++) {
		visited[i] = true;
		DFS(i + 1, index + 1);
		visited[i] = false;
	}

}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> S[i][j];
		}
	}

	DFS(1, 0); // 숫자는 1부터, 인덱스는 0부터 시작

	cout << myMin;
}