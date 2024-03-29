#include <string>
#include <vector>
using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    long long dp[2001]={1,1};
    
    for(int i=2; i<=n; i++){
        dp[i]=dp[i-2]+dp[i-1];
        if(dp[i]>1234567) dp[i]%=1234567;
    }
    
    answer=dp[n];
    
    return answer;
}