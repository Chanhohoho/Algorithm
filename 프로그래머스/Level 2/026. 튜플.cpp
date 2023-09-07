#include <string>
#include <vector>
//시간복잡도 터질듯
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    int len = s.size();
    vector<string> arr(1000000,"");
    string temp="";
    int cnt=1;
    int maxCnt=-1;
    
    for(int i=0; i<len; i++){
        if(s[i]=='{') continue;
        else if(s[i]=='}'){
            arr[cnt]=temp;        
            temp="";
            if(maxCnt<cnt) maxCnt=cnt;
            cnt=1;
            i++;
        }
        else{
            if(s[i]==',') cnt++;
            temp += s[i];
        }
    }
    
    answer.push_back(stoi(arr[1]));

    for(int i=2; i<=maxCnt; i++){
        arr[i]+=',';
        
        for(int j=0; j<arr[i].size(); j++){
            if(arr[i][j]==','){
                int flag = 0;
                int now = stoi(temp);
                temp="";
                for(int k=0; k<answer.size(); k++){
                    if(answer[k]==now){
                        flag=1;
                        break;
                    }
                }
                if(!flag){
                    answer.push_back(now);
                    break;
                } 
            }
            else temp+=arr[i][j];
        }
    }
        
    return answer;
}