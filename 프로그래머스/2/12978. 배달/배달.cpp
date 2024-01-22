#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;

//다익스트라
int solution(int N, vector<vector<int> > road, int K) {
    vector<vector<edge> > mlist(N+1);
    vector<int> mdistance(N+1, INT_MAX);
    
    for(auto i: road) {
        mlist[i[0]].push_back({i[1], i[2]});
        mlist[i[1]].push_back({i[0], i[2]});
    }
    
    priority_queue<edge, vector<edge>, greater<edge> > q;
    q.push({0,1});
    mdistance[1] = 0;
    
    while(!q.empty()) {
        edge curr = q.top();
        q.pop();
        
        for(auto i: mlist[curr.second]) {
            int next = i.first;
			int value = i.second;

			if (mdistance[next] > mdistance[curr.second] + value) {
				mdistance[next] = mdistance[curr.second] + value;
				q.push({ mdistance[next],next });
			}
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= N; i++) {
		if (mdistance[i] <= K) answer++;
	}
    return answer;
}