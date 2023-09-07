#include <string>
#include <vector>

using namespace std;

int len;
int ans;
int gone[7]={0};

void dfs(int now, int k, vector<vector <int>> dungeons){

    if(now==len){
        ans = now;
        return;
    }
    
    for(int i=0; i<len; i++) {
        if(gone[i]!=0) continue;
        if(k<dungeons[i][0]) continue;
        k-=dungeons[i][1];
        gone[i]=1;
        dfs(now+1, k, dungeons);
        gone[i]=0;
        k+=dungeons[i][1];
    }
    
    if(now>ans) ans=now;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    len = dungeons.size();

    dfs(0, k, dungeons);
    
    answer = ans;
    
    return answer;
}