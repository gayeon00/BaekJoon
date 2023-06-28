// QUICK11004.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& A, int S, int E, int K);
int partition(vector<int>& A, int S, int E);
void swap(vector<int>& A, int i, int j);

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);

    //입력 받기
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    quickSort(A, 0, N - 1, K - 1);
    cout << A[K - 1];
}

void quickSort(vector<int>& A, int S, int E, int K) {
    int pivot = partition(A, S, E);
    //pivot이 K번째 수면 더 구할 필요 없음
    if (pivot == K) {
        return;
    } else if (K < pivot) {
        quickSort(A, S, pivot - 1, K);
    } else {
        quickSort(A, pivot + 1, E, K);
    }
}

int partition(vector<int>& A, int S, int E) {
    //시작점이랑 끝점이 바로 붙어 있으면 
    //즉 A의 길이가 2이면
    if (S + 1 == E) {
        if (A[S] > A[E]) {
            swap(A, S, E);
        }
        return E;
    }

    //중앙 인덱스
    int M = (S + E) / 2;
    //중앙값을 첫번 째 요소랑 바꿈
    swap(A, S, M);
    int pivot = A[S];
    //시작점, 끝점 세팅
    int i = S + 1, j = E;

    while (i <= j) {
        //pivot작은 값이 나올 때 까지 --;
        while (pivot < A[j] && j > 0) {
            j--;
        }
        //pivot보다 큰 값이 나올 때까지 i++
        while (pivot > A[i] && i < A.size() - 1) {
            i++;
        }
        if (i <= j) {
            //i, j자리바꾸기
            swap(A, i++, j--);
        }
    }

    //i==j 피벗의 값을 양쪽으로 분리한 가운데에 오도록 설정
    A[S] = A[j];
    A[j] = pivot;
    return j;
}

void swap(vector<int>& A, int i, int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}