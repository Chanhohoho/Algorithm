#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> l, vector<int> r){
    return l[1]<r[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), cmp);
    
    int len = targets.size();
    
    int stand = -1;
    
    for(int i=0; i<len; i++){
        int s = targets[i][0];
        int e = targets[i][1];
        
        if(stand<=s){
            // cout<<"---------------"<<endl;
            stand = e;
            answer++;
        }
        // cout<<targets[i][0]<<' '<<targets[i][1]<<endl;
    }
    return answer;
}