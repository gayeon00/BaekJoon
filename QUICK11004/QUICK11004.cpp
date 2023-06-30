#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void quickSort(vector<int>& A, int S, int E, int K);

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> A(N);

	//숫자 입력받기
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	quickSort(A, 0, N - 1, K - 1);
	cout << A[K - 1];
}

void swap(vector<int>& A, int S, int E) {
	int tmp = A[S];
	A[S] = A[E];
	A[E] = tmp;
}

int partition(vector<int>& A, int S, int E) {
	//길이가 2이면
	if (S + 1 == E) {
		//정렬만 해줌
		if (A[S] > A[E]) {
			swap(A, S, E);
		}
	}

	//중앙값
	int M = (S + E) / 2;
	//중앙값을 맨 앞으로 옮겨줌
	swap(A, S, M);
	int pivot = A[S];
	//start, end 설정
	int i = S + 1, j = E;

	while (i <= j) {
		while (A[j] > pivot && j > 0) {
			j--;
		}

		while (A[i] < pivot && i < A.size() - 1) {
			i++;
		}

		//j--하고 i++하면 i <= j 조건에 안맞게 될수도 있으니까 조건 걸어줘야함
		if (i <= j) {
			//찾은 i데이터랑 j데이터를 swap
			swap(A, i++, j--);
		}
	}
	//이렇게 하고 나면 한 쪽은 pivot보다 작은 숫자들만, 한 쪽은 pivot보다 큰 숫자들만 옴!

	//pivot이랑 A[j] 바꿔줌
	A[S] = A[j];
	A[j] = pivot;
	return j;
}

void quickSort(vector<int>& A, int S, int E, int K) {
	int pivot = partition(A, S, E);
	if (pivot == K) {
		return;
	} else if (K < pivot) {
		quickSort(A, 0, pivot - 1, K);
	} else {
		quickSort(A, pivot + 1, E, K);
	}

}