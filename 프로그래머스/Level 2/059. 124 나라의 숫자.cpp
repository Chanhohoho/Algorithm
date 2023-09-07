#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
    
    string answer="";
    
    if(n<=3) {
        if(n==3) n=4;
        return to_string(n);
    }
    
    int cnt = 0;    //자리수
    int cntNum = 1; //자리수가 증가할때 증가하는 표시가능 수
    int nowMax = 0; //표시할 수 있는 가장 큰 수
    bool flag = 1;
    
    while(1){
        if(nowMax >= n) break;
        cntNum*=3;
        nowMax+=cntNum;
        cnt++;
    }

    int arr[] = {1,2,4};
    
    while(cnt){
        int nowNum;
        
        int now = 1;
        for(int i=1; i<cnt; i++) now*=3;
        
        nowNum=n/now;
        if(n%now==0 && flag) nowNum--;
        n-=nowNum*now;
        if(flag) answer+=to_string(nowNum==3?4:nowNum);
        else answer+=to_string(arr[nowNum]);
        
        if(flag) flag = !flag;
        
        cnt--;
        cout<<answer<<endl;
    }

    return answer;
}