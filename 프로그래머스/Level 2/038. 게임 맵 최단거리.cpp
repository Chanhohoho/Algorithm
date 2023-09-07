#include<vector>
#include<queue>
using namespace std;

struct node{
    int r,c,cnt;
};

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    
    int r = maps.size();
    int c = maps[0].size();
//     int map[100][100];    
//     for(int i=0; i<r; i++) for(int j=0; j<c; j++) map[i][j]=maps[i][j];
    
    queue<node> q;
    q.push({0,0,1});
    maps[0][0]=-1;
    while(!q.empty()){
        
        node now = q.front();
        q.pop();
        
        int dr[] = {0,0,1,-1};
        int dc[] = {1,-1,0,0};
        
        for(int i=0; i<4; i++){
            int nr = now.r+dr[i];
            int nc = now.c+dc[i];
            if(nr<0 || nc<0 || nr==r || nc==c || maps[nr][nc]!=1) continue;
            if(nr==r-1 && nc==c-1) return now.cnt+1;        
            q.push({nr,nc,now.cnt+1});
            maps[nr][nc]=-1;
        }
    }
    
    
    return answer;
}