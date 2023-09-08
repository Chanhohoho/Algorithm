#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    int cnt1=0;
    for(int i=n; i>0; i/=2) if(i%2==1) cnt1++;
    
    int now = n+1;
    int check = -1; // 1의 갯수
    
    while(cnt1!=check){
        
        check=0;
        for(int i=now; i>0; i/=2) if(i%2==1) check++;
        now++;
        
    }
    
    answer = now-1;
    
    return answer;
}