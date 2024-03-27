#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 20000;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> mlist(n+1);
    for(auto e: edge) {
        mlist[e[0]].push_back(e[1]);
        mlist[e[1]].push_back(e[0]);
    }
    vector<int> mdistance(n+1, MAX);
    mdistance[0] = 0;
    mdistance[1] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    
    while(!pq.empty()) {
        pair<int,int> now = pq.top();
        int now_node = now.second;
        
        pq.pop();
        
        for(auto next_node: mlist[now_node]) {
            if(mdistance[next_node] > mdistance[now_node] + 1) {
                mdistance[next_node] = mdistance[now_node] + 1;
                pq.push({mdistance[next_node], next_node});
            }
        }
    }
    

    auto max_distance = max_element(mdistance.begin(), mdistance.end());
    for(int i=1;i<=n;i++) {
        if(mdistance[i]==*max_distance) answer++;
        
    }
    return answer;
}