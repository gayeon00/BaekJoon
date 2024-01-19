#include <string>
#include <vector>
#include <queue>

using namespace std;

void munion(int a, int b);
int find(int a);
vector<int> parent;

typedef struct Edge {
    int s, e, v;
    bool operator > (const Edge& temp) const {
        return v > temp.v;
    }
} Edge;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;//가중치 기준 오름차순 정렬
    parent.resize(n);
    
    //부모노드 초기화
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    for(auto i: costs) {
        pq.push(Edge{i[0],i[1],i[2]});
    }
    
    //연결된 엣지 갯수 -> n-1이 되면 끝
    int useEdge = 0;
    while(useEdge!=n-1) {
        Edge now = pq.top();
        pq.pop();
        
        if(find(now.s) != find(now.e)) {
            munion(now.s,now.e);//연결하기
            answer += now.v;
            useEdge++;
        }
    }
    
    return answer;
}

void munion(int a, int b) {
    a = find(a);
    b = find(b);
    
    if(a!=b) {
        parent[b] = a;
    }
}

int find(int a) {
    if(a == parent[a]) {
        return a;
    } else {
        return parent[a] = find(parent[a]);
    }
}