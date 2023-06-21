// SORT2750.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int A[1001];
int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (A[j] > A[j + 1]) {
				int tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << A[i] << '\n';
	}
}




//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> a;
//
//    for (int i = 0; i < n; i++) {
//        int tmp;
//        cin >> tmp;
//        a.push_back(tmp);
//    }
//
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - 1 - i; j++) {
//            if (a[j+1] < a[j]) {
//                int tmp = a[j + 1];
//                a[j + 1] = a[j];
//                a[j] = tmp;
//            }
//        }
//    }
//
//    for (int i = 0; i < n; i++) {
//        cout << a[i] << '\n';
//    }
//}
