#include <string>
#include <vector>
using namespace std;

int arr[60001] = {1, 1,};

int dp(int now){
    for(int i=2; i<=now; i++) arr[i]=(arr[i-1]+arr[i-2])%1000000007;
    return arr[now];
}

int solution(int n) {
    return dp(n);
}