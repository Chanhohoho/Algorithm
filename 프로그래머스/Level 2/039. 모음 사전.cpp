#include <string>
#include <vector>
using namespace std;

int answer, flag;
string s = "AEIOU";

void check(int now, string word, string temp){
    
    if(now==5) return;
    
    for(int i=0; i<5; i++){
        answer++;
        string nowWord = temp + s[i];
        if(nowWord == word){//찾았을 때
            flag=1;
            break;
        }
        check(now+1, word, nowWord);
        if(flag) break;//찾았다
    }

}

int solution(string word) {

    check(0, word, "");
    
    return answer;
}