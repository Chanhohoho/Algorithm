#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node{
    int priority;
    int loca;
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<node> q;
    int nowPriority=0;
    int len = priorities.size();
    
    for(int i=0; i<len; i++) q.push({priorities[i], i});
    sort(priorities.begin(), priorities.end());
    reverse(priorities.begin(), priorities.end());
    
    while(!q.empty()){
        node now = q.front();
        q.pop();
        
        if(now.priority==priorities[nowPriority]){
            nowPriority++;
            if(now.loca==location) break;
            continue;
        }
        
        q.push(now);
    }
    
    return nowPriority;
}