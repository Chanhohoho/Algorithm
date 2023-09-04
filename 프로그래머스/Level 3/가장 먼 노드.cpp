#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<int> v[20001];    
    for(int i=0; i<edge.size(); i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);  
    }
    
    int dist[20001];
    for(int i=1; i<=n; i++){
        dist[i]=50001;
    }
    
    dist[1]=0;
    queue<int> pq;
    pq.push(1);
    int max=0;
    while(!pq.empty()){
        int now = pq.front();
        // cout<<pq.top();
        pq.pop();
        for(int i=0; i<v[now].size(); i++){
            if(dist[v[now][i]]>dist[now]+1){
                dist[v[now][i]]=dist[now]+1;
                pq.push(v[now][i]);
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(max<dist[i]) max=dist[i];
    }
    
    for(int i=1; i<=n; i++){
        if(dist[i]==max) answer++;
    }
    return answer;
}