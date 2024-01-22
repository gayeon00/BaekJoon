#include <vector>
#include <iostream>
using namespace std;

int result = 0;

void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

bool isSumPrime(const vector<int>& combination) {
    int sum = 0;
    for(int i = 0; i < 3; i++) {
        sum += combination[i];
    }
    
    //2~자기자신-1 숫자 중 나누어떨어지는 수가 있다면 즉, 약수가 있다면 얘는 prime이 아니므로 false를 return
    for(int i = 2; i < sum; i++) {
        if(sum % i ==0) {
            return false;
        }
    }
    
    return true;
}

//arr에서 start인덱스부터, n개 중 r개를 선택해서 combination에 담는다.
void findCombinations(const vector<int>& arr, int start, int n, int r, vector<int>& combination) {
    if (r == 0) {
        // printVector(combination);
        if(isSumPrime(combination)) {
            result++;
        }
        return;
    }
    
    for (int i = start; i <= n - r; ++i) {
        combination.push_back(arr[i]);
        findCombinations(arr, i + 1, n, r - 1, combination);
        combination.pop_back();
    }
}

int solution(vector<int> nums) {
    

    int n = nums.size();
    int r = 3;
    
    vector<int> combination;
    findCombinations(nums, 0, n, r, combination);

    return result;
}