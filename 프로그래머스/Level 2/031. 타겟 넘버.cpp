#include <string>
#include <vector>
using namespace std;

int sum;
int len;
int ans;

void dfs(int now, vector<int> numbers, int target){
    if(now==len){
        if(sum == target) {
            ans++;
        }
        return;
    }
    
    sum+=numbers[now];
    dfs(now+1, numbers, target);
    sum-=numbers[now];
    sum-=numbers[now];
    dfs(now+1, numbers, target);
    sum+=numbers[now];
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    len = numbers.size();
    
    dfs(0,numbers, target);
    
    answer = ans;
    
    return answer;
}