#include <string>
#include <vector>
#include <cmath>
using namespace std;

int len;
string number;

int answer = 0;
int check[7] = {0};
int dat[10000000] = {0};
string ans = "        ";

void checkNumber(string ans){
    int now = stoi(ans);
    if(now == 0 || now == 1) return;
    for(int i=2; i<=sqrt(now); i++){
        if(now%i==0){
            return;
        }
    }
    answer++;
}

void makeNumber(int now){
    if(now == len){
        return;
    }
    for(int i=0; i<len; i++){
        if(check[i]!=0) continue;
        check[i]=1;
        ans[now]=number[i];
        if(dat[stoi(ans)]==0) {
            dat[stoi(ans)]=1;
            checkNumber(ans);
        }
        makeNumber(now + 1);
        ans[now]=' ';
        check[i]=0;    
    }
}

int solution(string numbers) {
    len = numbers.size();
    number = numbers;
    makeNumber(0);
    
    return answer;
}