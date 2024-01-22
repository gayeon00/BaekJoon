#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int maxWinCount = 0;
vector<int> maxCombination;

void calculateAllDiceSums(int currentSum, int remainingDice, vector<vector<int>>& dice, vector<int>& path, vector<int>& result) {
    // 기저 조건: 주사위를 모두 굴렸을 때
    if (remainingDice == 0) {
        result.push_back(currentSum);
        return;
    }

    for (int i = 0; i < dice.size(); ++i) {
        for (int j = 0; j < dice[i].size(); ++j) {
            path.push_back(dice[i][j]);
            calculateAllDiceSums(currentSum + dice[i][j], remainingDice - 1, dice, path, result);
            path.pop_back();
        }
    }
}

//indexes 주사위를 굴려서 나오는 숫자들의 합의 모든 경우의 수 구하는 함수
vector<int> getAllDiceSums(const vector<vector<int>>& dice, vector<int> diceIndexes) {
    vector<int> result;

    vector<vector<int>> adice;
    for (auto i : diceIndexes) {
        adice.push_back(dice[i]);
    }
    vector<int> path;
    // 초기 호출
    calculateAllDiceSums(0, dice.size(), adice, path, result);

    return result;

}

int getWinCount(const vector<vector<int>>& dice, const vector<int>& adice) {
    //dice중에 a는 adice 고른 상황에서 a가 몇번 이기는지
    vector<int> bdice;

    for (int i = 0; i < dice.size(); i++) {
        if (find(adice.begin(), adice.end(), i) == adice.end()) {
            bdice.push_back(i);
        }
    }

    vector<int> allASums = getAllDiceSums(dice, adice);
    vector<int> allBSums = getAllDiceSums(dice, bdice);
    int count = 0;
    for (auto i : allASums) {
        for (auto j : allBSums) {
            if (i > j) count++;
        }
    }
    return count;
}

void findCombination(const vector<vector<int>>& dice, int start, int r, vector<int>& combination) {
    if (r == 0) {
        //combination에 들어있는 int가 선택된 dice의 index
        for (auto i : combination) {
            cout << i << ' ';
        }
        cout << '\n'; \


            //combination을 선택했을 때 이기는 횟수 구하기
            int winCount = getWinCount(dice, combination);
        if (maxWinCount < winCount) {
            maxWinCount = winCount;
            //deepcopy해야 하나?
            maxCombination = combination;
        }


        return;
    }

    for (int i = start; i <= dice.size() - r; i++) {
        combination.push_back(i);
        findCombination(dice, i + 1, r - 1, combination);
        combination.pop_back();
    }
}

vector<int> solution(vector<vector<int>> dice) {

    vector<int> combination;
    findCombination(dice, 0, dice.size() / 2, combination);

    for (int i = 0; i < maxCombination.size(); i++) {
        maxCombination[i]++;
    }
    return maxCombination;
}