#include <string>
#include <vector>

using namespace std;
int sum[500][500]={0};

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    sum[0][0]=triangle[0][0];
    
    int len = triangle.size();
    for(int i=1; i<len; i++){
        for(int j=0; j<=i; j++){
            
            int now = triangle[i][j];
            
            if(j==0){
                sum[i][j]=sum[i-1][j]+now;    
            }
            else if(j==i){
                sum[i][j]=sum[i-1][j-1]+now;
            }
            else{
                int bigger;
                if(sum[i-1][j]>=sum[i-1][j-1]) bigger=sum[i-1][j];
                else bigger=sum[i-1][j-1];
                
                sum[i][j]=bigger+now;
            }
            
            if(sum[i][j]>answer) answer=sum[i][j];
        }        
    }
    
    return answer;
}