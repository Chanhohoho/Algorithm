#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    int len = discount.size();
    for(int i=0; i<len-9; i++){
        unordered_map<string, int> now;
        int flag=0;
        for(int j=0; j<10; j++) now[discount[i+j]]++;
        for(int j=0; j<want.size(); j++){
            if(now[want[j]]!=number[j]){
                flag=1;
                break;
            }
        }
        if(flag) continue;
        else answer++;
    }
    
    return answer;
}