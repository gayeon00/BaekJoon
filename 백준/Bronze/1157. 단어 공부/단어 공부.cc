#include <iostream>
#include <string>

int main(){
    std::string S;
    std::cin >> S;
    int count[26] = {0};

    for(int i=0;i<S.length();i++){
        S[i] = tolower(S[i]);
        count[S[i]-97]++;
    }

    int max = 0;
    int cnt = 0;
    int target;
    for(int i=0;i<26;i++){
        if(count[i]>max){
            max = count[i];
            cnt = 0;
            target = i;
        }
        if(max ==count[i]){
            cnt++;
        }
    }
    if(cnt>1){
        std::cout << "?" <<std::endl;
    }
    else {
        std::cout << (char) (target + 'A') << std::endl;
    }
}