#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    
    int answer = 0;
    
    int dp[10001]={0};
    
    for(int i=0; i<citations.size(); i++){
        dp[citations[i]]++;    
    }
    int i;
    for(i=9999; i>=0; i--){
        dp[i]=dp[i]+dp[i+1];
        if(dp[i]>=i) break;
    }
   
    answer=i;
    return answer;
}