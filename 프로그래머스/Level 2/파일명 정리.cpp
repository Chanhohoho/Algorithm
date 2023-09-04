#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    string file, head;
    int number;
};

string isUpper(string s){
    string ans = "";
    
    int len = s.size();
    for(int i=0; i<len; i++){
        if(s[i]>='a' && s[i]<='z') ans+=s[i]-'a'+'A';
        else ans+=s[i];
    }
    
    return ans;
}

bool cmp(node front, node back){
    
    if(front.head==back.head){
        if(front.number==back.number){
            return false;
        } 
        return front.number < back.number;
    } 
    else return front.head<back.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<node> temp;
    
    int len = files.size();
    
    for(int i=0; i<len; i++){
        int idx = files[i].size();
        node now; now.file = files[i];
        
        string s = "";
        int j=0;
        for(; j<idx; j++){
            if(files[i][j]<'0' || files[i][j]>'9') s+=files[i][j];
            else break;
        }
        now.head = isUpper(s);
        s = "";
        
        int numberLen = j+5;
        for(; j<numberLen; j++){
            if(j==idx) break;
            if(files[i][j]>='0' && files[i][j]<='9') s+=files[i][j];
            else break;
        }
        now.number = stoi(s);
        s = "";
        
        temp.push_back(now);
    }
    
    stable_sort(temp.begin(), temp.end(), cmp);
    for(int i=0; i<len; i++) answer.push_back(temp[i].file);
    
    return answer;
}