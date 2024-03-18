#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#include <limits.h>

using namespace std;

int N, W, H;
int Answer;
int dh[4] = { 1,0,-1,0 };
int dw[4] = { 0,-1,0,1 };
int countBlocks(int Map[15][12]) {
	int count = 0;
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			if (Map[h][w] != 0) {
				count++;
			}
		}
	}

	return count;
}

void crash(int h, int w, int Map[15][12]) {
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(h, w, Map[h][w]));
	Map[h][w] = 0;
	
	while (!q.empty()) {
		tuple<int, int, int> now = q.front();
		q.pop();

		int now_h = get<0>(now);
		int now_w = get<1>(now);
		int now_num = get<2>(now);

		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < now_num; j++) {
				int next_h = now_h + j * dh[i];
				int next_w = now_w + j * dw[i];

				if (next_h >= 0 && next_h < H && next_w >= 0 && next_w < W&& Map[next_h][next_w] != 0) {
					q.push(make_tuple(next_h, next_w, Map[next_h][next_w]));
					Map[next_h][next_w] = 0;
				}
				
			}
		}

	}

}

void gravity(int Map[15][12]) {
	for (int w = 0; w < W; w++) {

		vector<int> tmp;

		for (int h = 0; h < H; h++) {
			if (Map[h][w] != 0) {
				tmp.push_back(Map[h][w]);
				Map[h][w] = 0;
			}
		}

		int tmpSize = tmp.size();
		for (int i = 0; i < tmpSize; i++) {
			Map[H-1-i][w] = tmp.back();
			tmp.pop_back();
		}
	}
}

void dfs(int n, int Map[15][12]) {
	if (n == N) {
		Answer = min(Answer, countBlocks(Map));
		return;
	}

	for (int w = 0; w < W; w++) {
		//tmpMap으로 작업하기
		int tmpMap[15][12];
		copy(&Map[0][0], &Map[0][0] + 15 * 12, &tmpMap[0][0]);

		//h위치 구하기
		int h = 0;
		for (; h < H; h++) {
			if (Map[h][w] != 0) {
				break;
			}
		}
		//w번째 세로 줄에 벽돌이 하나도 없어서 아무것도 못 깨는 경우를 제외하고
		if (h != H) {
			//h,w 부수기
			crash(h, w, tmpMap);
			gravity(tmpMap);
			dfs(n + 1, tmpMap);
		} else {
			Answer = min(Answer, countBlocks(Map));
		}
	}
}

int main() {
	int test_case;
	int T;

	cin >> T;
	
	for (test_case = 1; test_case <= T; test_case++) {
		
		cin >> N >> W >> H;

		Answer = INT_MAX;

		int Map[15][12];
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				cin >> Map[h][w];
			}
		}

		dfs(0, Map);
		cout << "#" << test_case << " " << Answer << '\n';
	}
	return 0;
}