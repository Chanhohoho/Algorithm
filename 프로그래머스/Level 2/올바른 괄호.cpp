#include <string>
#include <vector>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int i=0;
    stack<int> st;
    
    while(i<s.size()){
        
        if(s[i]==')'){
            if(st.empty())   return false;
            else st.pop();
        }
        else {
            st.push(0);
        }
        
        i++;
    }
    
    if(!st.empty()) answer = false;
        
    return answer;
}