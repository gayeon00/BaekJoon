#include <string>
#include <vector>
#include <iostream>

using namespace std;

int count_table[51][51] = {0};
int gift_idx[51] = {0};
int result_gift[51] = {0};

vector<string> split(string, char);
int get_index_of(vector<string>&, string);
void print_table();

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    for(auto i: gifts) {
        vector<string> splited = split(i,' ');
        string a = splited[0];
        string b = splited[1];
        
        int idx_a = get_index_of(friends, a);
        int idx_b = get_index_of(friends, b);
        
        count_table[idx_a][idx_b]++;
        gift_idx[idx_a]++; //준 선물
        gift_idx[idx_b]--; //받은 선물
    }
    // print_table();
    // for(auto i: gift_idx) {
    //     cout << i << ' ';
    // }
    // cout << '\n';
    
    for(int i = 0; i < friends.size(); i++) {
        for(int j = i + 1; j < friends.size(); j++) {
            
            if(count_table[i][j] > count_table[j][i]) { //i가 j보다 준게 더 많다면 
                result_gift[i]++;
            } else if(count_table[i][j] < count_table[j][i]) {// j가 i보다 준게 더 많다면
                result_gift[j]++;
            } else {
                if(gift_idx[i] > gift_idx[j]) {
                    result_gift[i]++;
                } else if(gift_idx[i] < gift_idx[j]) {
                    result_gift[j]++;
                }
            }
            
        }
    }
    
    // for(auto i: result_gift) {
    //     cout << i << ' ';
    // }
    // cout << '\n';
    
    for(auto i: result_gift) {
        if(answer < i) {
            answer = i;
        }
    }
    
    return answer;
};

int get_index_of(vector<string>& friends, string fr) {
    int result = 0;
    for(int i = 0; i < friends.size(); i++) {
        if(friends[i]==fr) {
            result = i;
            break;
        }
    }
    return result;
}

void print_table() {
    for(int i = 0; i < 51; i++) {
        for(int j = 0; j < 51; j++) {
            cout << count_table[i][j] << ' ';
        }
        cout << '\n';
    }
};

vector<string> split(string str, char ch) {
    vector<string> result;
    string tmp;
    for(auto i: str) {
        if(i == ch) {
            result.push_back(tmp);
            tmp = "";
        } else {
            tmp.push_back(i);
        }
    }
    result.push_back(tmp);
    return result;
};