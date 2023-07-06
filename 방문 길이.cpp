#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct node{
    int r,c;
};

int solution(string dirs) {
    int answer = 0;
    int len = dirs.size();
    
    vector<node> map[11][11];
    
    int nowr=0, nowc=0;
    
    for(int i=0; i<len; i++){
    
        int nextr, nextc;
        if(dirs[i]=='U'){
            nextr=nowr+1;
            nextc=nowc;
        }
        else if(dirs[i]=='D'){
            nextr=nowr-1;
            nextc=nowc;
        }
        else if(dirs[i]=='R'){
            nextr=nowr;
            nextc=nowc+1;
        }
        else{
            nextr=nowr;
            nextc=nowc-1;
        }
        
        int l = map[nowr][nowc].size();
        
        nowr=nextr;
        nowc=nextc;
    }
    
    return answer;
}