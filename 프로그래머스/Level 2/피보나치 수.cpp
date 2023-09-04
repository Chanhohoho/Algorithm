#include <string>
#include <vector>
using namespace std;

int num[10000001]={0,1,};

int dp(int n){
    
    int now = 2;
    while(n>=now){
        num[now]=(num[now-2]+num[now-1])%1234567;
        now++;
    }
    return num[n];
}

int solution(int n) {
    int answer = 0;
    
    answer = dp(n);
    
    return answer;
}