#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int i = 1; i<=sqrt(yellow); i++){   
        // i - 노란색 카펫 세로길이
        // j - 노란색 카펫 가로길이
        if(yellow%i!=0) continue;
        int j = yellow/i;
        int brownNeed = (i+j)*2+4;
        
        if(brown == brownNeed){
            answer.push_back(j+2); // 가로 길이
            answer.push_back(i+2); // 세로 길이
            break;
        }
        
    }
    
    return answer;
}