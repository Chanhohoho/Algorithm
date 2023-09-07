#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string change(int n, int num){
    
    if(num==0) return "0";
    
    string ans = "";
    
    while(num!=0){
        if(num%n<10) ans+=to_string(num%n);
        else{
            if(num%n==10) ans+='A';
            if(num%n==11) ans+='B';
            if(num%n==12) ans+='C';
            if(num%n==13) ans+='D';
            if(num%n==15) ans+='F';
            if(num%n==14) ans+='E';
        }
        num/=n;
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int cnt=0;
    int num=0;
    int now=1;
    while(cnt!=t){
        
        string s = change(n,num++);
        
        for(int i=0; i<s.size(); i++){
            // cout<<s[i]<<endl;
            if(now==p) {
                cnt++;
                
                answer+=s[i];
                if(cnt==t) break;
            }

            now++;
            
            if(now==m+1) now=1;
        }
        
    }
    
    return answer;
}