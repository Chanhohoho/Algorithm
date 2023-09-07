#include <string>
#include <queue>
#include <vector>
using namespace std;

struct node{
    int y, cnt;
};

int solution(int x, int y, int n) {
    int answer = 0;
    if(x==y) return 0;
    
    queue<node> q;
    q.push({y,0});
    
    while(!q.empty()){
        node now = q.front();
        q.pop();
        
        if(now.y-n==x || (now.y/2==x && now.y%2==0) || (now.y/3==x && now.y%3==0)) return now.cnt+1;
        if(now.y-n>x) q.push({now.y-n, now.cnt+1});
        if(now.y%2==0) q.push({now.y/2, now.cnt+1});
        if(now.y%3==0) q.push({now.y/3, now.cnt+1});
    }
    
    return -1;
}