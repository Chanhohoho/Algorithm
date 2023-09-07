#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int len = speeds.size();
    int done = 0;
    
    while(1){
        int today = 0;
        for(int i=0; i<len; i++) if(progresses[i]<100) progresses[i]+=speeds[i];
        while(progresses[done]>=100 && done<len) {
            today++;
            done++;
        }
        if(today!=0) answer.push_back(today);
        if(done==len) break;
    }
    return answer;
}