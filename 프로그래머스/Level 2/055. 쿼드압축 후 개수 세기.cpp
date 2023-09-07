#include <string>
#include <vector>
using namespace std;

int map[1024][1024]={0};
int cnt0 = 0, cnt1 = 0;
int len;

void check(int nowLen){
    if(nowLen == 1) return;    
    
    for(int nowX = 0; nowX<len; nowX+=nowLen){
        for(int nowY = 0; nowY<len; nowY+=nowLen){
            //압축가능한지    
            if(map[nowX][nowY]==-1) continue;
            int flag = 0;
            for(int i=0; i<nowLen; i++){
                for(int j=0; j<nowLen; j++){
                    if(map[nowX][nowY]!=map[nowX+i][nowY+j]){
                        flag=1;
                        break;
                    }
                }if(flag) break;
            }
            //압축
            if(!flag){
                if(map[nowX][nowY]==0) cnt0-=nowLen*nowLen-1;
                else cnt1-=nowLen*nowLen-1;
                
                for(int i=0; i<nowLen; i++){
                    for(int j=0; j<nowLen; j++){
                        map[nowX+i][nowY+j]=-1;
                    }
                }
            }
        }
    }
    check(nowLen/2);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    len = arr.size();
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            map[i][j]=arr[i][j];
            if(arr[i][j]==0) cnt0++;
            if(arr[i][j]==1) cnt1++;
        }
    }
    
    check(len);
    
    answer.push_back(cnt0);
    answer.push_back(cnt1);
    
    return answer;
}