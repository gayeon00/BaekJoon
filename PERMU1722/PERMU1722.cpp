#include <iostream>

using namespace std;

int N, Q;
long F[21], S[21];
bool visited[21] = { false };

int main() {
	
	cin >> N >> Q;
	F[0] = 1;
	//각 자리수에서 만들 수 있는 경우의 수
	//ex)N=4 => 1번째 자리 : 1!개, 2번째 자리: 2!개
	for (int i = 1; i <= N; i++) {
		F[i] = F[i - 1] * i;
	}

	if (Q == 1) {
		long K;
		cin >> K;
		//i번째 자리에 들어올
		for (int i = 1; i <= N; i++) {
			//수들 1,2,3,4
			for (int j = 1, cnt = 1; j <= N; j++) {
				if (visited[j]) continue;
				//해당 숫자를 넣어서 3번째를 찾을 수 있으면
				if (K <= cnt * F[N - i]) {
					K -= (cnt - 1) * F[N - i];
					S[i] = j;
					visited[j] = true;
					break;
				}
				//해당 숫자를 넣었는데 2번째 까지만 되고 3번째를 찾을 수 없다면 -> 다음 숫자로 j바꿔야지
				cnt++;
			}
		}

		for (int i = 1; i <= N; i++) {
			cout << S[i] << ' ';
		}
	} else {
		//초기값이니까 일단 1번째 순서라고 초기화
		long k = 1;

		for (int i = 1; i <= N; i++) {
			cin >> S[i];
			long cnt = 0;

			//해당 숫자 전에 안쓴 숫자 있는지 확인
			for (int j = 1; j < S[i]; j++) {
				if (!visited[j]) cnt++;
			}

			//안쓴 숫자가 있다는 말은 해당 숫자에 해당하는 경우의수 건너뛰었다는 말이므로
			//순서에 큰 영향줌
			k += cnt * F[N - i];
			visited[S[i]] = true;
		}

		cout << k;
	}
}