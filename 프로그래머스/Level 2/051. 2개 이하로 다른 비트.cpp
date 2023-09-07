#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long f(long long now){
    
    if(now%2==0) return now+1;

    long long ans = now;
    
    int idx = 0;
    int flag = 1;
    int idx0 = -1;
    
    while(now!=0){
        if(now%2==0 && flag){
            flag=0;
            idx0 = idx;
        }
        idx++;
        now/=2;
    }
    
    long long p = 1;
    if(idx0!=-1){
        while(idx0){
            p*=2;
            idx0--;
        }
    }
    else{
        while(idx){
            p*=2;
            idx--;
        }
    }
    
    ans+=p/2;
    return ans;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i=0; i<numbers.size(); i++) answer.push_back(f(numbers[i]));
    return answer;
}