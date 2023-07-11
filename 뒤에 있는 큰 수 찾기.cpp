#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    int len = numbers.size();
    int big = -1;
    int idx;
    
    for(int i = len-1; i>=0; i--){
        if(numbers[i]>=big){
            answer.push_back(-1);
            big = numbers[i];
            idx = i;
        }
        else{
            for(int j=i+1; j<=idx; j++){
                if(numbers[j]>numbers[i]){
                    answer.push_back(numbers[j]);
                    break;
                }
            }
        }
        // cout<<answer.back()<<' ';
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}