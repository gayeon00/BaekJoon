// UNION1717.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;

//a의 대표노드 찾기
int find(int a) {
	if (parents[a] == a) return a;

	return parents[a] = find(parents[a]);
}


void myUnion(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		parents[b] = a;
	}
}

void checkSame(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) cout << "YES" << '\n';
	else		  cout << "NO" << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	parents.resize( n + 1 );

	//대표노드를 자기 자신으로 설정
	for (int i = 0; i <= n; i++) {
		parents[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int flag, a, b;
		cin >> flag >> a >> b;
		if (!flag) {
			//합집합
			myUnion(a, b);
		} else {
			checkSame(a, b);
		}
	}



}