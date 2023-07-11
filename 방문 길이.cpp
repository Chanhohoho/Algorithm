#include <string>
#include <unordered_map>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    int len = dirs.size();
    
    int nowx=0, nowy=0;
    unordered_map<string, int> line;
    
    for(int i=0; i<len; i++){
        
        int nextx, nexty;
        
        if(dirs[i]=='U'){
            nextx=nowx;
            nexty=nowy+1;
        }
        if(dirs[i]=='D'){
            nextx=nowx;
            nexty=nowy-1;
        }
        if(dirs[i]=='L'){
            nextx=nowx-1;
            nexty=nowy;
        }
        if(dirs[i]=='R'){
            nextx=nowx+1;
            nexty=nowy;
        }
        
        if(nextx<-5 || nextx>5 || nexty>5 || nexty<-5) continue;
        
        string s1 = to_string(nowx) + to_string(nowy) + to_string(nextx) + to_string(nexty);
        string s2 = to_string(nextx) + to_string(nexty) + to_string(nowx) + to_string(nowy);
        
        if(line[s1]==0 && line[s2]==0){//지나간적 있는지
            line[s1]=1;
            line[s2]=1;
            answer++;
        }
        
        nowx=nextx;
        nowy=nexty;
    }
    
    return answer;
}
