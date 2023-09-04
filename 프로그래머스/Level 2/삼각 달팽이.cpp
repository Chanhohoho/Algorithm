#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    int arr[1001][1001]={0};
    int now = n;
    int cnt = 0, cnt0 = 0;
    for(int i=1; i<=n; i++) cnt+=i;
    int nowX = 0, nowY = 0;
    int num = 1;
    
    int flag = 1;
    for(int i=1; i<=cnt; i++){        
        if(flag%3 == 1){
            arr[nowX++][nowY]=num++;
        }
        else if(flag%3 == 2){
            arr[nowX][nowY++]=num++;
        }
        else{
            arr[nowX--][nowY--]=num++;
        }
        cnt0++;
        if(cnt0==now){
            now--;
            cnt0=0;
            if(flag%3 == 1){
                nowX--;
                nowY++;
            }
            else if(flag%3 == 2){
                nowX--;
                nowY-=2;
            }
            else{
                nowX+=2;
                nowY+=1;
            }
            flag++;
        }
    }
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            answer.push_back(arr[i][j]);
        }
    }
    
    return answer;
}