#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    
    vector<int> answer;
    int i;
    string all = " ";
    
    for (i = 1; i < words.size(); i++) {
        all+=words[i-1]+" ";
        if (words[i - 1][words[i - 1].size() - 1] != words[i][0]) break;
        if(all.find(' ' + words[i] + ' ')!=string::npos) break;             // string.find(word) string에 word가 포함되어있는지 확인
    }
    
    if (i == words.size()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(i%n+1);
        answer.push_back(i/n+1);
    }
    
    return answer;
}