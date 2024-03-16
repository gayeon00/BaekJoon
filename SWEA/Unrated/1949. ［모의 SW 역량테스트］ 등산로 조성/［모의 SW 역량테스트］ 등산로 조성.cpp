
#include <iostream>
#include <vector>

using namespace std;

int N;
int K;
int maps[8][8];
bool visited[8][8];
int max_height;
vector<pair<int, int>> tops;
int level;
int answer;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void init_maps() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			maps[i][j] = 0;
		}
	}
}

void init_visited() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			visited[i][j] = false;
		}
	}
}

void dfs(int x, int y) {
	level++;
	if (!visited[x][y]) {
		visited[x][y] = true;
		answer = max(answer, level);
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && 0 <= ny && nx < N && ny < N && !visited[nx][ny] && maps[nx][ny] < maps[x][y]) {
				dfs(nx, ny);
			}
		}
		visited[x][y] = false;
	}
	level--;
}

int main(int argc, char** argv) {
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case) {
		init_maps(); //map 초기화
		init_visited();
		tops.clear(); // 젤 높은 봉우리 리스트 초기화
		max_height = 0; //젤 높은 봉우리의 높이 초기화
		answer = 0;//정답 초기화

		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> maps[i][j];
				max_height = max(max_height, maps[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (maps[i][j] == max_height) {
					tops.push_back(make_pair(i, j));
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				//i,j 각 지점에 대해 
				for (int k = 0; k <= K; k++) {
					//k만큼 깎기
					maps[i][j] -= k;
					for (auto top : tops) {
						//깎은 후 각 젤 높은 봉우리를 시작점으로 탐색하기
						if (i != top.first || j != top.second) {
							init_visited();
							level = 0;
							dfs(top.first, top.second);
						}
					}

					maps[i][j] += k;
				}
			}
		}

		cout << "#" << test_case << " " << answer << '\n';
		

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}