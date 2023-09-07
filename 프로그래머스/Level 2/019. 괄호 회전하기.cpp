#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = -1;
    s=s+s;
    
    for(int i=0; i<s.size()/2; i++){
        stack<char> st;

        for(int j=0; j<s.size()/2; j++){
            if(st.empty()) st.push(s[i+j]);
            else{
                if((st.top()=='[' && s[i+j]==']') || (st.top()=='{' && s[i+j]=='}') || (st.top()=='(' && s[i+j]==')')) st.pop(); 
                else st.push(s[i+j]);
            }
        }        
        
        if(st.empty())   answer++;
    }
    
    return answer+1;
}