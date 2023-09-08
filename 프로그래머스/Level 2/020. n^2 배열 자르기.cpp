#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(; left<=right; left++){
        
        int i = left/n; // 행
        int j = left%n; // 열

        if(i>=j) answer.push_back(i+1);
        else     answer.push_back(j+1);

    }

    return answer;
}