#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    
    long long sum = 0;
    int len1 = queue1.size();
    
    for(int i=0; i<len1; i++){
        sum += queue1[i];
        sum += queue2[i];
    }
    
    if(sum%2!=0) return -1;
    long long needSum = sum/2;
    
    vector<int> v;
    for(int i=0; i<len1; i++) v.push_back(queue1[i]);
    for(int i=0; i<len1; i++) v.push_back(queue2[i]);
    for(int i=0; i<len1; i++) v.push_back(queue1[i]);
    
    long long nowSum = 0;
    int len2 = v.size();
    int st = 0, ed = 0;
    
    for(; ed<len2; ed++){
        nowSum += v[ed];
        // cout<<ed+1<<": "<<nowSum<<" "<<st<<" "<<ed<<endl;
        if(nowSum == needSum) break;
        else if(nowSum < needSum) continue;
        else {
            while(nowSum > needSum){
                nowSum -= v[st];
                st++;    
            }
            if(nowSum == needSum) break;
        }
    }   
    
    if(nowSum != needSum) return -1;
    
//     int answer;
    
//     if(ed<=len1-1) answer = st + ed + len1 + 1;
//     else if (ed<=len1*2-1) answer = st + ed - len1 + 1;
//     else {
//         if(st>=len1) answer = st + ed +1 - len2;
//         else answer = st + ed + 1 - len1;
//     }
    
    int answer = st + ed - len1 + 1;
    return answer;
}