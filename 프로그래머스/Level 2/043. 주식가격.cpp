#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int len = prices.size();
    for(int i=0; i<len; i++){
        int flag=0, j=i+1;
        for(; j<len; j++){
            if(prices[i]<=prices[j]) continue;
            flag=1;
            answer.push_back(j-i);
            break;
        }
        if(!flag) answer.push_back(j-i-1);
    }
    
    return answer;
}