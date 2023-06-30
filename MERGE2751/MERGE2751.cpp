// MERGE2751.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
void merge_sort(int s, int e);

int N;
vector<int> A(N + 1);
vector<int> tmp(N + 1);
int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    merge_sort(1, N);

    for (int i = 1; i <= N; i++) {
        cout << A[i] << '\n';
    }
}

void merge_sort(int s, int e) {
    //중간점이 안나오는 길이면 이미 다 정렬돼있는 상태??
    if (e - s < 1) {
        return;
    }
    //중간점
    int m = s + (e - s) / 2;

    //재귀형태로 중간점 앞 부분, 뒷 부분 각각 sort
    //정렬돼있어야 병합정렬을 할 수 있은까
    merge_sort(s, m);
    merge_sort(m + 1, e);

    //이제 여기부터 A는 정렬돼있는 상태
    for (int i = s; i <= e; i++) {
        tmp[i] = A[i];
    }

    //결과 배열의 시작인덱스
    int k = s;
    int index1 = s;
    int index2 = m + 1;

    while (index1 <= m && index2 <= e) {
        //뒤 그룹의 첫 수가 더 작을 경우
        if (tmp[index1] > tmp[index2]) {
            //결과 배열에 넣어주고
            A[k] = tmp[index2];
            k++;
            //뒤 그룹 인덱스++
            index2++;
        } else {
            A[k] = tmp[index1];
            k++;
            index1++;
        }
    }

    //한쪽 그룹이 모두 선택된 후 남은 값 정리하기
    while (index1 <= m) {
        A[k] = tmp[index1];
        k++;
        index1++;
    }
    while (index2 <= e) {
        A[k] = tmp[index2];
        k++;
        index2++;
    }
}
