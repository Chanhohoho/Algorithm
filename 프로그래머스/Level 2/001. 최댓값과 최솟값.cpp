#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    
    int i = 0;
    string temp = "";
    int maxN = -123456789;
    int minN = 123456789;
    
    while(i<s.size()){
        
        if(s[i]==' '){
            int now = stoi(temp);
            if(maxN<now) maxN=now;
            if(minN>now) minN=now;
            temp = "";
        }
        else    temp+=s[i];
        
        i++;
        
    }
    
    int now = stoi(temp);
    if(maxN<now) maxN=now;
    if(minN>now) minN=now;

    answer = to_string(minN) + ' ' + to_string(maxN);
    
    return answer;
}