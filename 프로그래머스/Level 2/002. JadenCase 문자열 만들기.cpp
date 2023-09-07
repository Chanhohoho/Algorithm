#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    
    int i = 0;
    bool check = true;
    
    while(i<s.size()){
    
        if(s[i]==' ') {
            check=true;
        }
        else if(check){
            if(s[i]>='a' && s[i]<='z') s[i]+='A'-'a';
            check=false;
        }
        else{
            if(s[i]>='A' && s[i]<='Z') s[i]+='a'-'A';
        }
        
        i++;
    }
    
    answer = s;
    
    return answer;
}