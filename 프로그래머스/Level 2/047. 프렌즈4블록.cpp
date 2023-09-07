#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct node {
    int i,j;
};

int solution(int m, int n, vector<string> board) {
    int answer = 0;   
    
    // 맵 복사
    // 2*2 확인
    // 펑
    // 블록 내려오기
    
    // 맵 복사
    char arr[30][30];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = board[i][j];
        }
    }
    
    while(1){
        // 2*2 확인
        queue<node> q;
        int xx[3] = {0,1,1};
        int yy[3] = {1,1,0};
        for(int i=0; i<m-1; i++){
            for(int j=0; j<n-1; j++){
                if(arr[i][j]=='-') continue;
                char now = arr[i][j];
                int flag=0;
                for(int k=0; k<3; k++){
                    if(now!=arr[i+xx[k]][j+yy[k]]) {
                        flag=1;
                        break;
                    }
                }
                if(!flag) q.push({i,j});
            }
        }

        // 끝났으면 탈출
        if(q.empty()) break;
        
        // 펑
        while(!q.empty()){
            node now = q.front();
            q.pop();
            arr[now.i][now.j]='-';
            for(int k=0; k<3; k++) arr[now.i+xx[k]][now.j+yy[k]] = '-';
        }

        // 블록 내려오기
        for(int i=m-2; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(arr[i][j]=='-') continue;
                char now = arr[i][j];
                int k = 1;
                while(arr[i+k][j]=='-' && i+k<m){
                    k++;
                }
                arr[i][j]='-';
                arr[i+k-1][j]=now;
            }
        }
    }
        
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]=='-') answer++;
        }
    }
    
    return answer;
}