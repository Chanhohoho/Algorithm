#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    answer.push_back(0);
    answer.push_back(0);
    
    while(s!="1"){
        int cnt1 = 0;
        
        for(int i=0; i<s.size(); i++){  // s의 모든 0을 제거
            if(s[i]=='1') cnt1++;
        }
        answer[1]+=s.size()-cnt1;
        
        s="";
        
        for(; cnt1>0; cnt1/=2){         // s의 길이를 2진법으로 표현
            if(cnt1%2==1) s='1'+s;
            else s='0'+s;
        }
        
        answer[0]++;
    }
    
    return answer;
}