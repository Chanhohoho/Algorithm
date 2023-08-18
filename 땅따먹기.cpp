#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    int dp[100000][4]={land[0][0],land[0][1],land[0][2],land[0][3],};
    int len = land.size();
    
    for(int i=1; i<len; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                if(k==j) continue;
                int now=dp[i-1][k]+land[i][j];
                if(now>dp[i][j]) dp[i][j]=now;
            }
        }    
    }

    for(int i=0; i<4; i++) if(dp[len-1][i]>answer) answer=dp[len-1][i];
    
    return answer;
}