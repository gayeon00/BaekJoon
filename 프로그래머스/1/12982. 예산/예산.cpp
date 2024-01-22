#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int result = 0;
    sort(d.begin(), d.end());
    for(auto i: d) {
        budget -= i;
        if(budget >= 0){
            result++;    
        }
        
    }
    
    return result;
}