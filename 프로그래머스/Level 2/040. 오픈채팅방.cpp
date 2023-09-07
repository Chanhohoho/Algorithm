#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    
    vector<string> answer;
    
    int len = record.size();
    
    unordered_map<string, string> id2name;
    
    for(int i=0; i<len; i++){
        
        int first = record[i].find(' ');
        int second = record[i].find(' ', first+1);
        int idLen = second - first - 1;
        string nowID = record[i].substr(first+1, idLen);
        
        if(record[i][0]!='L') id2name[nowID]=record[i].substr(second+1);
        
        if(record[i][0]=='E') answer.push_back(nowID + "님이 들어왔습니다.");
        
        if(record[i][0]=='L') answer.push_back(nowID + "님이 나갔습니다.");
            
    }
    
    len = answer.size();
    cout<<answer[0].find('님');
    
    for(int i=0; i<len; i++) {
        int idLen = answer[i].find(' ')-6; // find 메소드는 한글을 찾지 못한다 + 한글은 한글자에 3byte라 "님이" 두글자 제거
        answer[i]=id2name[answer[i].substr(0,idLen)]+answer[i].substr(idLen);
    }


    return answer;
}