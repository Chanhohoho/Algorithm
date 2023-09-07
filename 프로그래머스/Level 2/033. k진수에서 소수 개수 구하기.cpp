#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int n, int k) {
    int answer = 0;
    
    string s = "";    
    while(n!=0){
        s+=to_string(n%k);
        n/=k;
    }
    reverse(s.begin(), s.end());

    string temp="";
    int i;
    for(i=0; i<s.size(); i++){
        if(s[i]!='0') temp+=s[i];
        else{
            if(temp=="") continue;
            if(temp!="1") {
                int now = stoi(temp);
                int flag=0;
                for(int j=2; j<=now/2; j++){
                    if(now%j==0){
                        flag=1;
                        break;
                    }
                }
                if(!flag) answer++;
            }
            temp="";
        }
    }
    
    if(temp!="1" && temp!="") {
        long long now = stol(temp);
        int flag=0;
        for(long long j=2; j<=sqrt(now); j++){
            if(now%j==0){
                flag=1;
                break;
            }
        }
        if(!flag) answer++;
    }
    return answer;
}