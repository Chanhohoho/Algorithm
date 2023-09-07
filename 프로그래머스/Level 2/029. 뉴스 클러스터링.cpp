#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    
    int answer = 0;
    int cnt=0, cnt1=0, cnt2=0;
    unordered_map<string, int> arr1;
    
    int len1 = str1.size();
    int len2 = str2.size();
    for(int i=0; i<len1; i++) if(str1[i]>='A' && str1[i]<='Z') str1[i]+='a'-'A';
    for(int i=0; i<len2; i++) if(str2[i]>='A' && str2[i]<='Z') str2[i]+='a'-'A';
    
    for(int i=0; i<len1-1; i++){
        if(str1[i]>='a' && str1[i]<='z' && str1[i+1]>='a' && str1[i+1]<='z'){
            string temp = to_string(str1[i])+' '+to_string(str1[i+1])+' ';
            arr1[temp]++;
            cnt1++;
        }
    }
    
    for(int i=0; i<len2-1; i++){
        if(str2[i]>='a' && str2[i]<='z' && str2[i+1]>='a' && str2[i+1]<='z'){
            string temp = to_string(str2[i])+' '+to_string(str2[i+1])+' ';
            if(arr1[temp]!=0) {
                arr1[temp]--;
                cnt++;  
            }
            cnt2++;
        }
    }
    
    if(cnt1==0 && cnt2==0) answer=65536;
    else answer = 65536*cnt/(cnt1+cnt2-cnt);
    
    return answer;
}