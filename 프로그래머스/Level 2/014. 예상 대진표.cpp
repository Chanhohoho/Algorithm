#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int a, int b){
    int answer = 0;

    queue<int> q;
    for(int i=1; i<=n; i++) q.push(i);
    int last = 0;
    
    while(!q.empty()){
        int num1=q.front(); q.pop();
        int num2=q.front(); q.pop();
        if(last>=num2) answer++;    // 라운드 끝났는지 체크
        last=num2;
        if((num1==a || num1==b) && (num2==a || num2==b)) break;
        else if(num1==a || num1==b){
            q.push(num1);
        }
        else if(num2==a || num2==b){
            q.push(num2);
        }
        else{
            q.push(num2);
        }
    }
    
    return answer+1;
}