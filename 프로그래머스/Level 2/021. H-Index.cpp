#include <string>
#include <vector>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    int dp[10001]={0};
    
    for(int i=0; i<citations.size(); i++){
        dp[citations[i]]++;    
    }
    
    for(int i=9999; i>=0; i--){
        dp[i]=dp[i]+dp[i+1];
        if(dp[i]>=i) {
            answer = i;
            break;
        }
    }

    return answer;
}